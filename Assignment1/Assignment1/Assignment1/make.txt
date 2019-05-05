
CC=gcc
CFLAGS=-I.

hellomake: Assignment1.cpp Animation.cpp Frame.cpp
     $(CC) -o hellomake hellomake.o hellofunc.o -I