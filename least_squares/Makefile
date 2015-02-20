###
#
# This Makefile will compile the c files in this directory
#
###

CC = gcc
args = -O -Wall

all:: test

least_squares: least_squares.c
	$(CC) $(args) -o least_squares least_squares.c

test: least_squares
	./least_squares test.txt

###
# clean workspace
###
clean::
	rm -f least_squares

