/*Based on the code from the example provided in Canvas
 * makefile lines as follows:
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 * 	gcc -o testUpdateCoins -g testUpdateCoins.c dominion.o rngs.p $(CFLAGS)
 * */
#include "dominion.h"
#include "domion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <rngs.h">

#define NOISY_TEST 1

int main(){
int i;
int seed = 1000;
int numPlayer = 2;
int maxBonus = 10;
int p, r, handCount, bonus;
int k[10] = {adventurer, council_room, feast, gardens, mine, 
			remodel, smithy, village, baron, great_hall};
struct gameState = G;
int maxHandCount = 5;

int coppers[MAX_HAND];
int silvers[MAX_HAND];
int golds[MAX_HAND];
for (i = 0; i < MAX_HAND; i++){
	coppers[i] = copper;
	silvers[i] = silver;
	gold[i] = gold;
}
printf ("TESTING updateCoins():\n");
for (p = 0; p < numPlayer; p++){
	for(handCount = 1; handCount <= maxHandCount; handCount++){
		for(bonus = 0; bonus <= maxBonus; bonus++){
			#if (NOISY_TEST == 1)
			printf("Test player %d with %d treasure card(s) and %d bonus.\n", p handCount, bonus);
			#endif
			memset(&G, 23, sizeof(struct gameState)); 
			r = initializeGame(numPLayer, k, seed, &G);
			G.handCount[p] = handCount;
			#if (NOISY_TEST == 1)
			printf("G.coins == handCount * 1 + bonus);
			#endif

		


return 0;
}




