#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

//test card Adventurer
int main (int argc, char** argv) {
	struct gameState G;
	int result, rando = 0;
	int temphand[MAX_HAND];
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	rando = rand() % 10;
	result = initializeGame(2, k, rando, &G);
	assert(result == 0);
	printf("Card Test 1:\n");
	
	//test invalid input, drawntreasure not initialized at or reset to 0.
	result = adventurerCard(&G, 1, 1, temphand);
	assert(result == 0);
	
	//test invalid input, drawntreasure not initialized at or reset to 0.
	result = adventurerCard(&G, 1, -1, temphand);
	assert(result == 0);
	
	//test valid input
	result = adventurerCard(&G, 1, 0, temphand);
	assert(result == 0);
	
	printf("TEST SUCCESSFULLY COMPLETED.\n");
	return 0;
}