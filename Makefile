CC=g++
DEPENDECIES=-I/usr/local/include
SIMLIB=-L/usr/local/lib64 -lsimlib -lm 
SRC=*.cc
OBJ=main

# main:
# 	$(CC) $(DEPENDENCIES) $(SIMLIB)  main.cc -o $(OBJ)

# mac:
# 	$(CC) -o $(OBJ) main.cc model.cc

all: 
	$(CC) $(DEPENDENCIES) $(SIMLIB) -o $(OBJ) $(SRC)

PARSER=parser.cc model.cc
parser:
	$(CC) $(PARSER) -o $(OBJ)

model:
	$(CC) $(DEPENDENCIES) $(SIMLIB) -o $(OBJ) $(SRC)
	
	# Default beta, delta, nu values are 0.9, 0.08, 0.125 respectively. It's considered as the worst case scenario.

	# no lockdown but schools and bars are shut down
	./main > nolockdown.dat
	# lockdown and everything is close
	./main -l > lockdown.dat
	# everything is open
	./main --school --bar > open.dat
	

clean:
	rm $(OBJ) 

.PHONY: mac clean