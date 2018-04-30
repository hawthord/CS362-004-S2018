#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//test function buyCard()
int main(int argc, char ** argv){
	struct gameState G;
	int result, rando = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	rando = rand() % 10;
	result = initializeGame(2, k, rando, &G);
	assert(result == 0);
	printf("Unittest 2:\n");
	
	G.coins = 5;
	G.numBuys = 2;
	
	//Testing multiple bad inputs
	result = buyCard(-2, &G);
	assert(result == -1);
	
	//testing multiple good inputs
	result = buyCard(2, &G);
	assert(result == 0);
	
	printf("TEST SUCCESSFULLY COMPLETED.\n");
	return 0;
}