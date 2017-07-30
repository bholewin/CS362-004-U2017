/*
Bryce Holewinski
CS362, Section 400
This is part of the random tests suites
It will test a particular function in
dominion.c. Formatting based on other
testing files already provided
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "assertTrue.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

//This random test will go over the adventurer card
//The adventurer card has a bug where the player draws an extra treasure card
int adventurerCardTest(int p, struct gameState *post)
{
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));
  //call adventurer
  int callStatus;
  callStatus = adventurerCall(post);
  assert(callStatus == 0);

  //now we need to build out the preconditions so they can be tested against the
  //post conidtions
  int find, found = 0;
  for (find = 0; find < pre.deckCount[p]; find++)
  {
    if (pre.deck[p][find] == copper || pre.deck[p][find] == silver || pre.deck[p][find] == gold)
      found++;
    else if(pre.discard[p][find] == copper || pre.discard[p][find] == silver || pre.discard[p][find] == gold)
      found++;
  }

  if (found > 1)
    pre.handCount[p] += 2;
  else if (found == 1)
    pre.handCount[p] += 1;

  memcpy(pre.deck[p], post->deck[p], sizeof(int) * MAX_DECK);
  memcpy(pre.discard[p], post->discard[p], sizeof(int) * MAX_DECK);
  memcpy(pre.hand[p], post->hand[p], sizeof(int) * MAX_HAND);
  memcpy(pre.playedCards, post->playedCards, sizeof(int) * MAX_DECK);

  pre.deckCount[p] = post->deckCount[p];
  pre.discardCount[p] = post->discardCount[p];

  callStatus = assertTrue(memcmp(&pre, post, sizeof(struct gameState)) == 0, "Game states are equal");

  //now we will check on the call status in case it fails and run through the
  //battery of tests
  if (callStatus)
  {
    printf("Time to check the variance between the different game states.\n");
    printf("Pre handCount: %d, Post handCount: %d\n",pre.handCount[p], post->handCount[p]);
    printf("Pre deckCount: %d, Post deckCount: %d\n",pre.deckCount[p], post->deckCount[p]);
    assertTrue(pre.numPlayers == post->numPlayers, "Same number of players.\n");
    assertTrue(pre.whoseTurn == post->whoseTurn, "Proper turn.\n");
    assertTrue(pre.phase == post->phase, "Correct phase.\n");
    assertTrue(pre.numActions == post->numActions, "Equal number of actions.\n");
    assertTrue(memcmp(pre.playedCards, post->playedCards, sizeof(int)* MAX_DECK)== 0, "Proper # of played cards.\n");
    assertTrue(pre.playedCardCount == post->playedCardCount, "Same number of played cards.\n");
    assertTrue(memcmp(pre.hand[0], post->hand[0], sizeof(int) * MAX_HAND) == 0, "1 in hand.\n");
		assertTrue(pre.handCount[0] == post->handCount[0], "handCount = 1.\n");
		assertTrue(memcmp(pre.deck[0], post->deck[0], sizeof(int) * MAX_DECK) == 0, "1 in deck.\n");
		assertTrue(pre.deckCount[0] == post->deckCount[0], "deckCount = 1.\n");
		assertTrue(memcmp(pre.discard[0], post->discard[0], sizeof(int) * MAX_DECK) == 0, "discard = 1.\n");
    assertTrue(pre.discardCount[0] == post->discardCount[0], "discardCount = 1.\n");

    assertTrue(memcmp(pre.hand[1], post->hand[1], sizeof(int) * MAX_HAND) == 0, "2 in hand.\n");
		assertTrue(pre.handCount[1] == post->handCount[1], "handCount = 2.\n");
		assertTrue(memcmp(pre.deck[1], post->deck[1], sizeof(int) * MAX_DECK) == 0, "2 in deck.\n");
		assertTrue(pre.deckCount[1] == post->deckCount[1], "deckCount = 2.\n");
		assertTrue(memcmp(pre.discard[1], post->discard[1], sizeof(int) * MAX_DECK) == 0, "discard = 2.\n");
    assertTrue(pre.discardCount[1] == post->discardCount[1], "discardCount = 2.\n");

    assertTrue(memcmp(pre.hand[2], post->hand[2], sizeof(int) * MAX_HAND) == 0, "3 in hand.\n");
		assertTrue(pre.handCount[2] == post->handCount[2], "handCount = 3.\n");
		assertTrue(memcmp(pre.deck[2], post->deck[2], sizeof(int) * MAX_DECK) == 0, "3 in deck.\n");
		assertTrue(pre.deckCount[2] == post->deckCount[2], "deckCount = 3.\n");
		assertTrue(memcmp(pre.discard[2], post->discard[2], sizeof(int) * MAX_DECK) == 0, "discard = 3.\n");
    assertTrue(pre.discardCount[2] == post->discardCount[2], "discardCount = 3.\n");

    assertTrue(memcmp(pre.hand[3], post->hand[3], sizeof(int) * MAX_HAND) == 0, "4 in hand.\n");
		assertTrue(pre.handCount[3] == post->handCount[3], "handCount = 4.\n");
		assertTrue(memcmp(pre.deck[3], post->deck[3], sizeof(int) * MAX_DECK) == 0, "4 in deck.\n");
		assertTrue(pre.deckCount[3] == post->deckCount[3], "deckCount = 4.\n");
		assertTrue(memcmp(pre.discard[3], post->discard[3], sizeof(int) * MAX_DECK) == 0, "discard = 4.\n");
    assertTrue(pre.discardCount[3] == post->discardCount[3], "discardCount = 4.\n");

  }
  return callStatus;
}

//main file builds the post gameState and creates the testing loop
int main()
{
  int i, j, k, n, p;

  //char buffer[1024];
  //int k[10] = {adventurer, council_room, feast, gardens, mine,
	       //remodel, smithy, village, baron, great_hall};

  struct gameState G;

  //handle random by seeding it
  srand(time(NULL));


  //r = initializeGame(2, k, 1, &G);

  printf("*************************************************\n");
  printf("This test will check the adventurer card.\n");
  for (n = 0; n < 15000; n++)
  {
    //initialize the game, basically drawn from dominion.c
    for (i = 0; i < sizeof(struct gameState); i++)
    {
      ((char*)&G)[i] = floor(Random()*256);
    }
    p = floor(Random() * 4);
    G.whoseTurn = p;
    //build the decks
    for (j = 0; j < 4; j++)
    {
      G.deckCount[j] = floor(Random() * MAX_DECK/2);
      G.discardCount[j] = floor(Random() * MAX_DECK/2);
      G.handCount[j] = floor(Random() * MAX_DECK/2);
    }
    //allocate treasure cards
    for (i = 0; i < 4; i++)
    {
      for (j = 0; j < MAX_HAND; j++)
      {
        G.hand[i][j] = floor(Random() * treasure_map);
        G.deck[i][j] = floor(Random() * treasure_map);
        G.discard[i][j] = floor(Random() * treasure_map);
      }
    }
    for (i = 0; i < MAX_DECK; i++)
    {
      G.playedCards[i] = floor(Random() * treasure_map);
    }
    G.playedCardCount = floor(Random() * MAX_DECK/3);
    adventurerCardTest(p, &G);
  }
  printf("End of adventurer testing.\n");
  return 0;
}
