#include <iostream>
#include "default.h"
#include "simulation.h"

using namespace std;

#define STEP 0.2

#include "simlib.h"

SEIR seir(DBETA, DDELTA, DNU, DPOPULATION);

void Sample(){ seir.sample(); }

Sampler Sampler(Sample, STEP);

void Model::simulate() {
    cout << "[+] Simulation...\n";
    seir.setIntegrators(SUSCEPTIBLE, EXPOSED, INFECTED, RECOVERED);
    if (LOCKDOWN == 1) {
        cout << "[+] Lockdown...\n";
    } else {
        cout << "No Lockdown...\n";
    }
    // Initialize output file to store results
    SetOutput("seir.dat");
    // 1 experiment
    for (int i = 0; i < 1; i++) {
        Print("\n");
        seir.setParameters(BETA, DELTA, NU, POPULATION, LOCKDOWN, BAR, SCHOOL);
        Print("# Time S E I R \n");
        Init(0, 100);
        Run();
    }
}
