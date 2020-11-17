#include <iostream>

#include "simlib.h"
#include "parser.h"

using namespace std;

struct SEIR {
    Integrator S, E, I, R;
    SEIR(float beta, float omega, float nu, int N):
        S(-beta * S * I/N, SUSCEPTIBLE), // dS(t)dt=−βS(t)I(t)N
        E(beta * S * I/N - omega * E, EXPOSED), // dE(t)dt=βS(t)I(t)N−δE(t)
        I(omega * E - nu * I, INFECTED), // dI(t)dt=δE(t)−νI(t)
        R(nu * I, RECOVERED) {} // dR(t)dt=vI(t)
};

SEIR SEIR(0.8, 0.09, 0.12, 1000);

// Output
void Sample() { 
    Print("%6.2f %g %g %g %g\n", T.Value(), SEIR.S.Value(), SEIR.E.Value(), SEIR.I.Value(), SEIR.R.Value());
}

Sampler Sampler(Sample, STEP);

int main(int argc, char **argv) {
    cout << "SEIR model\n";   

    // Parse input 
    if (parse(argc, argv) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    cout << "Simulating...";

    Init(SSTART_TIME, SEND_TIME); // up to 100 days    

    Run();
}