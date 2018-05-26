#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define REPS 10000
#define DEBUGGER2

int checkAdventurer(int player, struct gameState *post, int handpos) {

	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

#ifdef DEBUGGER2
	int decksize = pre.deckCount[player] + pre.handCount[player] + pre.discardCount[player];
	printf("Pre-test state:\nPlayer %d/%d - Full Deck: %d, Draw Pile:%d/%d, Hand: %d/%d, Discard: %d/%d\n",
		player + 1, pre.numPlayers,
		decksize,
		decksize - pre.handCount[player] - pre.discardCount[player],
		decksize,
		pre.handCount[player],
		decksize,
		pre.discardCount[player],
		decksize);
#endif

	int r, s, i;
//	int handpos = 0; // A!!!!!!!!!!!!
	r = cardAdventurer(post, player, handpos);

	int cardDrawn;
	int z = 0;	// counter for extra cards drawn
	int drawntreasure = 0;
	int temphand[MAX_DECK];

	while (drawntreasure < 2) {

		s = drawCard(player, &pre);	// separate unit
		if (s == -1) break;			// break if hand contains full deck -- no cards left to draw or shuffle

		cardDrawn = pre.hand[player][pre.handCount[player] - 1]; //top card of hand is most recently drawn card.

		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			(drawntreasure)++;
		else {
			temphand[z] = cardDrawn;
			pre.handCount[player]--; //this should just remove the top card (the most recently drawn one).
			(z)++;
		}
	}
	for (i = z; i > 0; i--) {
		pre.discard[player][pre.discardCount[player]++] = temphand[i - 1];
	}

	discardCard(handpos, player, &pre, 0);

#ifdef DEBUGGER2
	decksize = pre.deckCount[player] + pre.handCount[player] + pre.discardCount[player];
	printf("Pre-with-mutation:\nPlayer %d/%d - Deck: %d, Draw Pile:%d/%d, Hand: %d/%d, Discard: %d/%d\n",
		player + 1, pre.numPlayers,
		decksize,
		decksize - pre.handCount[player] - pre.discardCount[player],
		decksize,
		pre.handCount[player],
		decksize,
		pre.discardCount[player],
		decksize);
	decksize = post->deckCount[player] + post->handCount[player] + post->discardCount[player];
	printf("Post-operation state:\nPlayer %d/%d - Deck: %d, Draw Pile:%d/%d, Hand: %d/%d, Discard: %d/%d\n",
		player + 1, post->numPlayers,
		decksize,
		decksize - post->handCount[player] - post->discardCount[player],
		decksize,
		post->handCount[player],
		decksize,
		post->discardCount[player],
		decksize);
#endif

	if (r == 0) { printf("Check 1 successful.\n"); }
	else printf("Card not played successfully.\n");	// call finished successfully
	if (memcmp(&pre, post, sizeof(struct gameState)) == 0) { printf("Check 2 successful.\n\n"); } 	// pre & post are the same
	else { printf("Failure -- mismatch.\n\n"); }  // pre and post are different



	return 0;
}

int main() {
	int i, player, k, handpos;
	
	printf("Testing Adventurer card randomly.\n");

	SelectStream(2);
	PutSeed(3);

	for (i = 0; i < REPS; i++) {

		struct gameState Game;
		int kcards[10] = { adventurer, council_room, feast, gardens, mine,
			remodel, smithy, village, ambassador, great_hall };
		int numplayers = rand() % 2 + 2;
		int numcards = rand() % 99 + 11;

		initializeGame(numplayers, kcards, 3, &Game);
		player = whoseTurn(&Game);

		gainCard(adventurer, &Game, 2, player);
		for (k = 0; k < 5; k++) {
			drawCard(player, &Game);
		}	// empty the deck into the hand.

		int toFlag = 2;	// gain to hand.

		int numInHand = Game.handCount[player];
		if (numcards - numInHand > 0) {
			numInHand += rand() % (numcards - numInHand); // 11 <= numInHand <= ~30
		}
		int numInDiscard = 0;
		if (numcards - numInHand > 0) { numInDiscard = rand() % (numcards - numInHand); }

		for (k = Game.handCount[player]; k < numcards; k++) {
			if (k > numInHand) {
				toFlag = 0; // gain to discard pile
			}
			if (k > numInHand + numInDiscard) {
				toFlag = 1;	// gain to deck
			}
			while (gainCard(rand() % 27, &Game, toFlag, player) == -1) { continue; } // gain a random card that IS in game.
		}

		for (k = 0; k < numcards; k++) {
			if (Game.hand[player][k] == adventurer) {
				handpos = k;
			}
		}
		checkAdventurer(player, &Game, handpos);
	}
	return 0;
}