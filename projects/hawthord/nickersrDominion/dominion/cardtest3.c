#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAmbassador(int player, struct gameState *post, int handpos, int choice1, int choice2) {
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int r, i;
	int j = 0;
	int tempHand[MAX_HAND];

	r = cardAmbassador(post, player, handpos, choice1, choice2);

	if (choice1 != handpos && choice2 >= 1 && choice2 <= 2) {
		for (i = 0; i < pre.handCount[player]; i++) {
			if (i == choice1 || pre.hand[player][choice1] == pre.hand[player][i]) { 
				tempHand[j] = i;
				j++;
				
			}
		}
	}
	
	if (j == choice2 && choice2 >= 1 && choice2 <= 2) { 
		
		for (i = 0; i < j; i++) {
			discardCard(tempHand[i], player, &pre, 1);
			pre.supplyCount[pre.hand[player][choice1]]++;
		}
		/*do stuff*/
		for (i = 0; i < pre.numPlayers; i++) {
			if (i != player) {
				gainCard(pre.hand[player][choice1], &pre, 0, i);
			}
		}

		discardCard(handpos, player, &pre, 0);
	}


	assert(r == 0);	// call finished successfully
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);	// pre & post are the same
	return 0;
}

int main() {

	int n, handpos;

	printf("Testing Ambassador.\n");
	printf("TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 1000; n++) {

	struct gameState Game;

	int kcards[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, ambassador, great_hall };

	initializeGame(4, kcards, 3, &Game);
	gainCard(ambassador, &Game, 2, Game.whoseTurn);

		for (handpos = 0; handpos <= Game.handCount[Game.whoseTurn]; handpos++) {
			if (Game.hand[Game.whoseTurn][handpos] == ambassador) {
				int choice1, choice2;
				for (choice2 = -1; choice2 <= 3; choice2++) {
					for (choice1 = 0; choice1 < Game.handCount[Game.whoseTurn]; choice1++) {
						if (checkAmbassador(Game.whoseTurn, &Game, handpos, choice1, choice2)) {
							printf("checkAmbassador Pass\n");
						}
						else {
							printf("checkAmbassador Fail\n");
						}
					}
				}
			}
		}
	}

	printf("ALL TESTS COMPLETED\n");

	return 0;
}
