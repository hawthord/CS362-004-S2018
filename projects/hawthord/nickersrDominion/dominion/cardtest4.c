#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkGreatHall(int player, struct gameState *post, int handpos) {
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int r;

	r = cardEffect(great_hall, 0, 0, 0, post, handpos, 0);

	drawCard(player, &pre);
	pre.numActions++;
	discardCard(handpos, player, &pre, 0);

	assert(r == 0);	// call finished successfully
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);	// pre & post are the same
	return 0;
}

int main() {

	int n, handpos;

	printf("Testing Great Hall.\n");
	printf("TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 1000; n++) {

		struct gameState Game;

		int kcards[10] = { adventurer, council_room, feast, gardens, mine,
			remodel, smithy, village, ambassador, great_hall };

		initializeGame(4, kcards, 3, &Game);
		gainCard(great_hall, &Game, 2, Game.whoseTurn);

		for (handpos = 0; handpos < Game.handCount[Game.whoseTurn]; handpos++) {
			if (Game.hand[Game.whoseTurn][handpos] == great_hall) {
				checkGreatHall(Game.whoseTurn, &Game, handpos);
			}
		}
	}
	
	printf("ALL TESTS COMPLETED\n");

	return 0;
}
