#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

#define DEBUG 0
#define NOISY_TEST 1

int checkUpdateCoins(int player, struct gameState *post, int bonus) {
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int r;

	r = updateCoins(player, post, bonus);

	/*test stuff here*/
	pre.coins = 0;
	int i;
	for (i = 0; i < pre.handCount[player]; i++) {
		if (pre.hand[player][i] == copper) { pre.coins += 1; }
		if (pre.hand[player][i] == silver) { pre.coins += 2; }
		if (pre.hand[player][i] == gold) { pre.coins += 3; }
	}
	pre.coins += bonus;
	
	assert(r == 0);	// call finished successfully
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);	// pre & post are the same
	return 0;
}

int main() {

	int n;

	printf("Testing updateCoins.\n");

	printf("TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 1000; n++) {

		struct gameState Game;

		int kcards[10] = { adventurer, council_room, feast, gardens, mine,
			remodel, smithy, village, ambassador, great_hall };

		initializeGame(4, kcards, 3, &Game);
		gainCard(gold, &Game, 2, Game.whoseTurn);
		gainCard(silver, &Game, 2, Game.whoseTurn);

		checkUpdateCoins(Game.whoseTurn, &Game, 0);
	}

	printf("ALL TESTS COMPLETED\n");

	return 0;
}
