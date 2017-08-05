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

unittestresults.out: dominion.o rngs.o assertTrue.o cardTest1.c cardTest2.c cardTest3.c cardTest4.c
	echo "Results for running dominion tests:" > unittestresults.out

	echo "cardTest1.c:" >> unittestresults.out
	gcc -o cardTest1 -g cardTest1.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	cardTest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardTest2.c:" >> unittestresults.out
	gcc -o cardTest2 -g cardTest2.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	cardTest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardTest3.c:" >> unittestresults.out
	gcc -o cardTest3 -g cardTest3.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	cardTest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardTest4.c:" >> unittestresults.out
	gcc -o cardTest4 -g cardTest4.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	cardTest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	cat dominion.c.gcov >> unittestresults.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o assertTrue.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o assertTrue.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o assertTrue.o
	echo "randomtestadventurer.c:" > randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	echo "dominion.c.gcov:" >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard1: randomtestcard1.c dominion.o rngs.o assertTrue.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o assertTrue.o $(CFLAGS)

randomtestcard1.out: randomtestcard1.c dominion.o rngs.o assertTrue.o
	echo "randomtestcard1.c:" > randomtestcard1.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	randomtestcard1 >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	echo "dominion.c.gcov:" >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2: randomtestcard2.c dominion.o rngs.o assertTrue.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o assertTrue.o $(CFLAGS)

randomtestcard2.out: randomtestcard2.c dominion.o rngs.o assertTrue.o
	echo "randomtestcard2.c:" > randomtestcard2.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o assertTrue.o $(CFLAGS)
	randomtestcard2 >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	echo "dominion.c.gcov:" >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

all: playdom player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2
