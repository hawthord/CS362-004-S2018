#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurer(int player, struct gameState *post, int handpos) {

	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int r, s, i;

	r = cardAdventurer(post, player);

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
		pre.discard[player][pre.discardCount[player]++] = temphand[i-1];
	}

	discardCard(handpos, player, &pre, 0);

	assert(r == 0);	// call finished successfully
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);	// pre & post are the same
	return 0;
}

int main() {

	//int i, n, deckCount, discardCount, handCount;
		int n, handpos;

	printf("Testing Adventurer.\n");

	printf("TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 1000; n++) {

		struct gameState Game;

		int kcards[10] = { adventurer, council_room, feast, gardens, mine,
			remodel, smithy, village, ambassador, great_hall };

		initializeGame(4, kcards, 3, &Game);
		gainCard(adventurer, &Game, 2, Game.whoseTurn);
		
		for (handpos = 0; handpos < Game.handCount[Game.whoseTurn]; handpos++) {
			if (Game.hand[Game.whoseTurn][handpos] == adventurer) {
				printf("Whoseturn is player %d\n", Game.whoseTurn);
				checkAdventurer(Game.whoseTurn, &Game, handpos);
			}
		}
	}

	printf("ALL TESTS COMPLETED\n");

	return 0;
}
