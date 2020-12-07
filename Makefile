CC=g++
DEPENDECIES=-I/usr/local/include
SIMLIB=-L/usr/local/lib64 -lsimlib -lm 
SRC=*.cc
OBJ=main

all: 
	$(CC) -o $(OBJ) $(SRC) -lsimlib -lm

model:
	$(CC) $(DEPENDENCIES) $(SIMLIB) -o $(OBJ) $(SRC)
	
	# Default beta, delta, nu values are 0.9, 0.08, 0.125 respectively. It's considered as the worst case scenario.

	########################################################## WORST CASE 
	# no lockdown but schools and bars are shut down
	./main --o=worstcase.dat
	# everything is open (school and bar)
	./main --school --bar --o=worstcaseschoolbar.dat
	########################################################## BEST CASE 
	# beta = 0.01 delta = 0.4 nu = 0.75 (the best-case scenario) 
	# no lockdown but schools and bars are shut down 
	./main --beta=1 --delta=40 --nu=75 --o=bestcase.dat
	# everything is open (school and bar)
	./main --beta=1 --delta=40 --nu=75 --school --bar --o=bestcaseschoolbar.dat
	########################################################## SECOND CASE
	# beta = 0.9 delta = 0.4 nu = 0.75 
	# no lockdown but schools and bars are shut down 
	./main --beta=90 --delta=40 --nu=75 --o=secondcase.dat
	# everything is open (school and bar)
	./main --beta=90 --delta=40 --nu=75 --school --bar --o=secondcaseschoolbar.dat
	# everything is open except school
	./main --beta=90 --delta=40 --nu=75 --bar --o=secondcasebar.dat
	# everything is open except bar
	./main --beta=90 --delta=40 --nu=75 --school --o=secondcaseschool.dat
	########################################################## THIRD CASE
	# beta = 0.5 delta = 0.4 nu = 0.75 
	./main --beta=50 --delta=40 --nu=75 --o=thirdcase.dat
	# everything is open (school and bar)
	./main --beta=50 --delta=40 --nu=75 --school --bar --o=thirdcaseschoolbar.dat
	# everything is open except school
	./main --beta=50 --delta=40 --nu=75 --bar --o=thirdcasebar.dat
	# everything is open except bar
	./main --beta=50 --delta=40 --nu=75 --school --o=thirdcaseschool.dat

lockdown:
	$(CC) $(DEPENDENCIES) $(SIMLIB) -o $(OBJ) $(SRC)
	# Default beta, delta, nu values are 0.9, 0.08, 0.125 respectively. It's considered as the worst case scenario.
	
	##########################################################
	# lockdown
	./main -l --o=lockdown.dat
	##########################################################
	# beta = 0.9 delta = 0.4 nu = 0.75 
	# lockdown
	./main --beta=90 --delta=40 --nu=75 --l --o=lockdowntwo.dat

PARSER=parser.cc model.cc
parser:
	$(CC) $(PARSER) -o $(OBJ)


clean:
	rm $(OBJ) 

.PHONY: model clean