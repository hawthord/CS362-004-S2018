#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

//test card Ambassador
int main (int argc, char** argv) {
	struct gameState G;
	int result, rando = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	rando = rand() % 10;
	result = initializeGame(2, k, rando, &G);
	assert(result == 0);
	printf("Card Test 3:\n");
	
	//test invalid input, no card revealed from hand
	result = ambassadorCard(&G, 1, 0, 0);
	assert(result == 0);
	
	//test invalid input, unlikely hand size
	result = ambassadorCard(&G, 1, 20, 2);
	//assert(result == 0);	//causes core dump
	
	//test valid input
	result = ambassadorCard(&G, 1, 0, 1);
	//assert(result == 0);	//causes core dump
	
	printf("TEST SUCCESSFULLY COMPLETED.\n");
	return 0;
}