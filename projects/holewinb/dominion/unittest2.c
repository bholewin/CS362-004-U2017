/*
Bryce Holewinski
CS362, Section 400
This is part of the unit tests suites
It will test a particular function in
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

  int r;
  int t; // testing variable

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  r = initializeGame(2, k, 1, &G);
  printf("*************************************************\n");
  printf("This test will check the numHandCards function.\n");
  t = numHandCards(&G);
  assertTrue(t == G.handCount[G.whoseTurn], "Hand count is proper.\n");
  assertTrue(t == 5, "5 starting cards.\n");
  printf("*************************************************\n");
  return 0;
}
