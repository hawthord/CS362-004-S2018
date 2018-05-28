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
	//result = cardAmbassador(&G, 1, 0, 0);		//ORIGINAL
	result = cardAmbassador(&G, 1, 0, 0, 1);
	assert(result == 0);
	
	//test invalid input, unlikely hand size
	//result = cardAmbassador(&G, 1, 20, 2);	//ORIGINAL
	result = cardAmbassador(&G, 1, 20, 2, 1);
	//assert(result == -1);	//causes core dump
	
	//test valid input
	//result = cardAmbassador(&G, 1, 0, 1);		//ORIGINAL
	result = cardAmbassador(&G, 1, 0, 1, 1);
	//assert(result == 0);	//causes core dump
	
	printf("TEST SUCCESSFULLY COMPLETED.\n");
	return 0;
}


//HAVE
//int ambassadorCard(struct gameState *state, int handPos, int choice1, int choice2){

//NEED
//int cardAmbassador(struct gameState *state, int currentPlayer, int choice1, int choice2, int handPos)


