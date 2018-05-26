CFLAGS = -Wall -fpic -coverage -lm

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

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe

cleanTests:
	rm -f cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c *.gcov *.gcda *.gcno *.out


unitTests: rngs.o
	touch dominion.c
	gcc -c dominion.c dominion.h rngs.o -g  $(CFLAGS)
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o -g  $(CFLAGS)
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o -g  $(CFLAGS)
	gcc -o unittest1 unittest1.c dominion.o rngs.o -g  $(CFLAGS)
	gcc -o unittest2 unittest2.c dominion.o rngs.o -g  $(CFLAGS)
	gcc -o unittest3 unittest3.c dominion.o rngs.o -g  $(CFLAGS)
	gcc -o unittest4 unittest4.c dominion.o rngs.o -g  $(CFLAGS)
	./cardtest1 &> unittestresults.out
	./cardtest4 &>> unittestresults.out
	./unittest1 &>> unittestresults.out
	./unittest2 &>> unittestresults.out
	./unittest3 &>> unittestresults.out
	./unittest4 &>> unittestresults.out
	gcov dominion.c	>> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
cardTest1: rngs.o
	touch dominion.c
	gcc -c dominion.c dominion.h rngs.o -g  $(CFLAGS)
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o -g  $(CFLAGS)
	./cardtest1 &> cardtest1result.out
	gcov dominion.c >> cardtest1result.out
	cat dominion.c.gcov >> cardtest1result.out

cardTest2: rngs.o
	touch dominion.c
	gcc -c dominion.c dominion.h rngs.o -g  $(CFLAGS)
	gcc -o cardtest2 cardtest2.c dominion.o rngs.o -g  $(CFLAGS)
	./cardtest2 &> cardtest2result.out
	gcov dominion.c >> cardtest2result.out
	cat dominion.c.gcov >> cardtest2result.out

cardTest3: rngs.o
	touch dominion.c
	gcc -c dominion.c dominion.h rngs.o -g  $(CFLAGS)
	gcc -o cardtest3 cardtest3.c dominion.o rngs.o -g  $(CFLAGS)
	./cardtest3 &> cardtest3result.out
	gcov dominion.c >> cardtest3result.out
	cat dominion.c.gcov >> cardtest3result.out

cardTest4: rngs.o
	touch dominion.c
	gcc -c dominion.c dominion.h rngs.o -g  $(CFLAGS)
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o -g  $(CFLAGS)
	./cardtest4 &> cardtest4result.out
	gcov dominion.c >> cardtest4result.out
	cat dominion.c.gcov >> cardtest4result.out

unitTest1: rngs.o
	touch dominion.c
	gcc -c dominion.c dominion.h rngs.o -g  $(CFLAGS)
	gcc -o unittest1 unittest1.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest1 &> unittest1result.out
	gcov dominion.c >> unittest1result.out
	cat dominion.c.gcov >> unittest1result.out

unitTest2: rngs.o
	touch dominion.c
	gcc -c dominion.c dominion.h rngs.o -g  $(CFLAGS)
	gcc -o unittest2 unittest2.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest2 &> unittest2result.out
	gcov dominion.c >> unittest2result.out
	cat dominion.c.gcov >> unittest2result.out

unitTest3: rngs.o
	touch dominion.c
	gcc -c dominion.c dominion.h rngs.o -g  $(CFLAGS)
	gcc -o unittest3 unittest3.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest3 &> unittest3result.out
	gcov dominion.c >> unittest3result.out
	cat dominion.c.gcov >> unittest3result.out

unitTest4: rngs.o
	touch dominion.c
	gcc -c dominion.c dominion.h rngs.o -g  $(CFLAGS)
	gcc -o unittest4 unittest4.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest4 &> unittest4result.out
	gcov dominion.c >> unittest4result.out
	cat dominion.c.gcov >> unittest4result.out

