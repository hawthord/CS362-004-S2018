#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

//test card Steward
int main (int argc, char** argv) {
	struct gameState G;
	int result, rando = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	rando = rand() % 10;
	result = initializeGame(2, k, rando, &G);
	assert(result == 0);
	printf("Card Test 4:\n");
	
	//test invalid input, no options selected
	result = stewardCard(&G, 1, 0, 0, 0);
	assert(result == 0);
	
	//test invalid input, all options selected
	result = stewardCard(&G, 1, 1, 1, 1);
	assert(result == 0);
	
	//test invalid input, multiple options selected
	result = stewardCard(&G, 1, 0, 1, 1);
	assert(result == 0);
	
	//test invalid input, multiple options selected
	result = stewardCard(&G, 1, 1, 0, 1);
	assert(result == 0);
	
	//test invalid input, multiple options selected
	result = stewardCard(&G, 1, 1, 1, 0);
	assert(result == 0);
	
	//test valid input, choice 1: +2 cards
	result = stewardCard(&G, 1, 1, 0, 0);
	assert(result == 0);
	
	//test valid input, choice 2, +2 coin
	result = stewardCard(&G, 1, 0, 1, 0);
	assert(result == 0);
	
	//test valid input, choice 3, trash two cards
	result = stewardCard(&G, 1, 0, 0, 1);
	assert(result == 0);
	
	printf("TEST SUCCESSFULLY COMPLETED.\n");
	return 0;
}