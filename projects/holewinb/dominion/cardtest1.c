/*
Bryce Holewinski
CS362, Section 400
This is part of the unit tests suites
It will test a particular card in
dominion.c. Formatting based on suppltTest.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "assertTrue.h"

int main () {

  int r, s;
  int t; // testing variable
  char buffer[1024];
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState OG;
  struct gameState currentG;

  r = initializeGame(2, k, 1, &OG);
  s = initializeGame(2, k, 1, &currentG);
  printf("*************************************************\n");
  printf("This test will check the smithy card. (Expect to find bugs)\n");
  smithyCall(&currentG, 0);
  assertTrue(OG.handCount[0] + 2 == currentG.handCount[0], "Player has 2 additional cards in hand after discarding smithy.");
  assertTrue(OG.deckCount[0] - 3 == currentG.deckCount[0], "The deck should have 3 less cards.");

  assertTrue(OG.handCount[1] == currentG.handCount[1], "Player 2's hand count is not modified.");
  assertTrue(OG.deckCount[1] == currentG.deckCount[1], "Player 2's deck is not modified.");

  printf("Check to make sure the player has less coins.\n");
  assertTrue(OG.coins - 4 == currentG.coins, "Coin amount was properly calculated.");

  printf("Check to make sure the treasure cards are not altered.\n");
  for (t = 0; t < treasure_map+1; t++)
  {
    sprintf(buffer, "Propper number of treasure card %d.\n", t);
    assertTrue(OG.supplyCount[t] == currentG.supplyCount[t], buffer);
  }

  printf("*************************************************\n");
  return 0;
}
