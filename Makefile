#Makefile for roman numeral calculator
C=gcc

CFLAGS=-c -Wall 
 
all: RomanTEST
	
RomanTEST: RomanCAL.o RomanCAL.h RomanTEST.o
	$(C) -g RomanTEST.o RomanCAL.o RomanCAL.h -o RomanTEST

RomanTEST.o: RomanTEST.c
	$(C) $(CFLAGS) RomanTEST.c

RomanCAL.o: RomanCAL.c
	$(C) $(CFLAGS) RomanCAL.c

clean:
	rm -rf *o RomanTEST
