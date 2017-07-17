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
  printf("This test will check the isGameOver function.\n");
  assertTrue(isGameOver(&G) == 0, "Game does not end when it begins.\n");
  printf("Check to make sure game ends when out of provinces.\n");
  G.supplyCount[province] = 0;
  assertTrue(isGameOver(&G) == 1, "Game ends when out of provinces.\n");
  printf("Check to make sure game ends when out of supply piles.\n");
  G.supplyCount[0] = 0;
  G.supplyCount[1] = 0;
  G.supplyCount[2] = 0;
  assertTrue(isGameOver(&G)==1, "Game ends when out of 3 supply piles.\n");
  printf("*************************************************\n");
  return 0;
}
