#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkGetCost(struct gameState *post, int cardNumber) {
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int r, s;
	r = getCost(cardNumber);
	
	switch (cardNumber)
	{
	case curse:
		s = 0;
		break;
	case estate:
		s = 2;
		break;
	case duchy:
		s = 5;
		break;
	case province:
		s = 8;
		break;
	case copper:
		s = 0;
		break;
	case silver:
		s = 3;
		break;
	case gold:
		s = 6;
		break;
	case adventurer:
		s = 6;
		break;
	case council_room:
		s = 5;
		break;
	case feast:
		s = 4;
		break;
	case gardens:
		s = 4;
		break;
	case mine:
		s = 5;
		break;
	case remodel:
		s = 4;
		break;
	case smithy:
		s = 4;
		break;
	case village:
		s = 3;
		break;
	case baron:
		s = 4;
		break;
	case great_hall:
		s = 3;
		break;
	case minion:
		s = 5;
		break;
	case steward:
		s = 3;
		break;
	case tribute:
		s = 5;
		break;
	case ambassador:
		s = 3;
		break;
	case cutpurse:
		s = 4;
		break;
	case embargo:
		s = 2;
		break;
	case outpost:
		s = 5;
		break;
	case salvager:
		s = 4;
		break;
	case sea_hag:
		s = 4;
		break;
	case treasure_map:
		s = 4;
		break;
	default:
		s = -1;
		break;
	}

	r -= s;

	assert(r == 0);	// call finished successfully
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);	// pre & post are the same
	return 0;
}

int main() {

	int i, n;

	
	printf("Testing getCost.\n");

	printf("TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 1000; n++) {

		struct gameState Game;
		int kcards[10] = { adventurer, council_room, feast, gardens, mine,
			remodel, smithy, village, ambassador, great_hall };

		initializeGame(4, kcards, 3, &Game);

		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&Game)[i] = floor(Random() * 256);
		}

		for (i = 0; i < 27; i++) {
			checkGetCost(&Game, i);
		}
	}

	printf("ALL TESTS COMPLETED\n");

	return 0;
}
