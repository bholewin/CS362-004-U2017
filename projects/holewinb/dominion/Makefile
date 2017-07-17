CFLAGS = -Wall -fpic -lm -O0 -ftest-coverage -fprofile-arcs

assertTrue.o: assertTrue.h assertTrue.c
		gcc -c assertTrue.c -g $(CFLAGS)

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o assertTrue.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o assertTrue.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o assertTrue.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o assertTrue.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o assertTrue.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o assertTrue.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o assertTrue.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o assertTrue.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o assertTrue.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o assertTrue.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o assertTrue.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o assertTrue.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o assertTrue.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o assertTrue.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o assertTrue.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o assertTrue.o $(CFLAGS)

unittestresult.out: dominion.o assertTrue.o rngs.o unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c
	echo "unittest1.c: " >> unittestresult.out
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	unittest1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "unittest2.c: " >> unittestresult.out
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	unittest2 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "unittest3.c: " >> unittestresult.out
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	unittest3 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "unittest4.c: " >> unittestresult.out
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	unittest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "cardtest1.c: " >> unittestresult.out
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	cardtest1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "cardtest2.c: " >> unittestresult.out
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	cardtest2 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "cardtest3.c: " >> unittestresult.out
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	cardtest3 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "cardtest4.c: " >> unittestresult.out
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	cardtest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
