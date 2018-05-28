#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//test function main() for game completion
int main(int argc, char ** argv){
	struct gameState G;
	int result, rando = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	rando = rand() % 10;
	result = initializeGame(2, k, rando, &G);
	assert(result == 0);
	printf("Unittest 1:\n");
	
	int i;
	for(i = 25; i >= 0; i--){
		G.supplyCount[i] = i;
		result = isGameOver(&G);
	}
	
	assert(result == 0);
	
	printf("TEST SUCCESSFULLY COMPLETED.\n");
	return 0;
}