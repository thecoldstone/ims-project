#include <iostream>
#include <stdlib.h>
#include "default.h"
#include "simulation.h"

using namespace std;

#define STEP 0.2

#include "simlib.h"

SEIR seir(DBETA, DDELTA, DNU, DPOPULATION);

void Sample(){ seir.sample(); }

Sampler Sampler(Sample, STEP);

void Model::simulate() {

    SetOutput(OUTPUTFILE);
    seir.setIntegrators(SUSCEPTIBLE, EXPOSED, INFECTED, RECOVERED);

    // 1 experiment
    for (int i = 0; i < 1; i++) {
        seir.setParameters(BETA, DELTA, NU, POPULATION, LOCKDOWN, BAR, SCHOOL);
        Print("# Time S E I R \n");
        Init(0, 100);
        Run();
    }
}
