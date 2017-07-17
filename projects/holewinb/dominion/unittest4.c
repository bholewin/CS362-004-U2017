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
  printf("This test will check the buyCard function.\n");
  printf("First check to make sure the player has buys left to use.\n");
  G.numBuys = 0;
  assertTrue(buyCard(2, &G) == 0, "Cannot purchase a card when out of buys.\n");
  G.numBuys = 1;
  printf("Check to make sure the player has enough coins.\n");
  G.coins = 0;
  assertTrue((buyCard(2, &G) == 0), "Cannot purchase a card when out of coins.");
  G.coins = 10;
  assertTrue((buyCard(2, &G) == 1), "Can purchase a card when you have the proper amount of coins.");
  printf("*************************************************\n");
  return 0;
}
