CC=g++
DEPENDECIES=-I/usr/local/include
SIMLIB=-L/usr/local/lib64 -lsimlib -lm 
SRC=*.cc
OBJ=main

# main:
# 	$(CC) $(DEPENDENCIES) $(SIMLIB)  main.cc -o $(OBJ)

mac:
	$(CC) -o $(OBJ) main.cc model.cc

all: 
	$(CC) $(DEPENDENCIES) $(SIMLIB) -o $(OBJ) $(SRC)

parser:
	$(CC) parser.cc -o $(OBJ)

clean:
	rm $(OBJ) 

.PHONY: mac clean