#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

//test card Smithy
int main (int argc, char** argv) {
	struct gameState G;
	int result, rando = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	rando = rand() % 10;
	result = initializeGame(2, k, rando, &G);
	assert(result == 0);
	printf("Card Test 2:\n");
	
	//test invalid input, invalid player hand position
	result = smithyCard(&G, 6);
	assert(result == 0);
	
	//test valid input
	result = smithyCard(&G, 1);
	assert(result == 0);
	
	printf("TEST SUCCESSFULLY COMPLETED.\n");
	return 0;
}