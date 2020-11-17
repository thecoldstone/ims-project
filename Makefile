CC=g++
DEPENDECIES=-I/usr/local/include
SIMLIB=-L/usr/local/lib64 -lsimlib -lm 
SRC=*.c
OBJ=model

all:
	$(CC) $(DEPENDENCIES) model.cc $(SIMLIB) -o $(OBJ)

parser:
	$(CC) parser.cc -o parser

clean:
	rm $(OBJ) 