#include <iostream>

#include "simlib.h"
#include "compartments.h"

using namespace std;

double STEP = 0.2;

// β, δ, ν
float beta, omega, nu;

// int S = 999 E = 1, I = 0, R = 0; 

struct SEIR {
    Integrator _S, _E, _I, _R;
    SEIR(float beta, float omega, float nu, int N):
        _S(-beta*_S*_I/N, 999), // dS(t)dt=−βS(t)I(t)N
        _E(beta*_S*_I/N - omega*_E, 1), // dE(t)dt=βS(t)I(t)N−δE(t)
        _I(omega*_E - nu*_I, 0), // dI(t)dt=δE(t)−νI(t)
        _R(nu*_I, 0) {} // dR(t)dt=vI(t)
};

SEIR SEIR(0.8, 0.09, 0.12, 1000);

// Output
void Sample() { 
    Print("%6.2f %g %g %g %g\n", T.Value(), SEIR._S.Value(), SEIR._E.Value(), SEIR._I.Value(), SEIR._R.Value());
}

Sampler Sampler(Sample, STEP);

int main(int argc, char **argv) {
    cout << "SEIR model\n";   

    Init(0,100); // up to 100 days    

    Run();
}