#include <iostream>
#include "simulation.h"

using namespace std;

#define STEP 0.2

#include "simlib.h"

// Default values
SEIR seir(0.9, 0.08, 0.125, 1000);

void Sample() { 
    Print("%6.2f %g %g %g %g\n", T.Value(), seir._S(), seir.E.Value(), seir.I.Value(), seir.R.Value());
}

Sampler Sampler(Sample, STEP);

void Model::simulate() {
    cout << "[+] Simulation...\n";
    seir.setIntegrators(SUSCEPTIBLE, EXPOSED, INFECTED, RECOVERED);
    seir.setParameters(0.9, 0.08, 0.125, POPULATION);
    Init(0, 100);
    Run();
}
