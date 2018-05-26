#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"

#define REPS 10000
//#define DEBUGGER2

int checkSmithy(int player, struct gameState *post, int handpos) {

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


	int r, i;

	r = cardSmithy(post, player, handpos);

	for (i = 0; i < 3; i++) {
		drawCard(player, &pre);	// presumably has already been unit-tested separately.
	}
	discardCard(handpos, player, &pre, 0); // presumably has already been unit-tested separately.


	if (r == 0) {	// check card called. 
		printf("Card call success.\n"); }	// call finished successfully
	else { printf("Card call failure.\n"); }

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
		decksize - pre.handCount[player] - pre.discardCount[player],
		decksize,
		post->handCount[player],
		decksize,
		post->discardCount[player],
		decksize);
#endif

	if (memcmp(&pre, post, sizeof(struct gameState)) == 0) {
		printf("Success.\n\n"); }	// pre & post are the same 
	else { printf("Failure.\n\n"); }

	return 0;
}

int main() {
	int i, player, k, handpos;
	handpos = -42;

	printf("Testing Smithy card randomly.\n");

	SelectStream(2);
	PutSeed(3);

	for (i = 0; i < REPS; i++) {

		struct gameState Game;
		int kcards[10] = { adventurer, council_room, feast, gardens, mine,
			remodel, smithy, village, ambassador, great_hall };
		int numplayers = rand() % 2 + 2;
		int numcards = rand() % 19 + 11;

		initializeGame(numplayers, kcards, 3, &Game);
		player = whoseTurn(&Game);

		gainCard(smithy, &Game, 2, player);
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
#ifdef DEBUGGER1
			printf("Card %d is %d\n", k, Game.hand[player][k]);
#endif
			if (Game.hand[player][k] == smithy) {
				handpos = k;
			}
		}
		checkSmithy(player, &Game, handpos);
	}
	return 0;
}