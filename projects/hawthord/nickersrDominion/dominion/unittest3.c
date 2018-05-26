#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkSupplyCount(struct gameState *post, int cardNumber) {
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int r, s;
	r = supplyCount(cardNumber, post);

	s = pre.supplyCount[cardNumber];

	r -= s;

	assert(r == 0);	// call finished successfully
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);	// pre & post are the same
	return 0;
}

int main() {

	int i, n;

	printf("Testing supplyCount.\n");

	printf("TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 1000; n++) {

		struct gameState Game;

		int kcards[10] = { adventurer, council_room, feast, gardens, mine,
			remodel, smithy, village, ambassador, great_hall };

		initializeGame(4, kcards, 3, &Game);

		for (i = 0; i < 27; i++) {
			checkSupplyCount(&Game, i);
		}
	}

	printf("ALL TESTS COMPLETED\n");

	return 0;
}
