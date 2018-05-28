#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//test function getCost()
//int getCost(int);
int main(int argc, char ** argv){
	struct gameState G;
	int result, value, rando = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	rando = rand() % 10;
	result = initializeGame(2, k, rando, &G);
	assert(result == 0);
	printf("Unittest 3:\n");
	
	//test bad case
	value = -1;
	result = getCost(value);
	//assert(result == -1);
	
	//testing good case
	value = 1;
	result = getCost(value);
	//assert(result == 0);
	value = 2;
	result = getCost(value);
	//assert(result == 2);
	
	printf("TEST SUCCESSFULLY COMPLETED.\n");
	return 0;
}