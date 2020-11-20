CC=g++
DEPENDECIES=-I/usr/local/include
SIMLIB=-L/usr/local/lib64 -lsimlib -lm 
SRC=*.cc
OBJ=main

mac:
	$(CC) -o $(OBJ) $(SRC)

# all: 
# 	$(CC) $(DEPENDENCIES) $(SIMLIB) -o $(OBJ) $(SRC)

parser:
	$(CC) parser.cc -o $(OBJ)

clean:
	rm $(OBJ) 

.PHONY: mac clean