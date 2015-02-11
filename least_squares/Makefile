###
#
# This Makefile will compile the c files in this directory
#
###

CC = gcc
args = -O -Wall

all:: squares

squares: least_squares.c
	$(CC) $(args) -o squares least_squares.c

test: squares
	./squares

###
# clean workspace
###
clean::
	rm -f squares


