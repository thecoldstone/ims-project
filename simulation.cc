#include <iostream>

//#include "simlib.h"
#include "model.h"
#include "simulation.h"

using namespace std;

void Model::simulate() {
    cout << "[+] Simulation...\n";

    //TODO 
}

// class SEIR {
//     public:
//         Parameter beta, omega, nu, n;
//         Integrator S, E, I, R;
//         SEIR(float _beta, float _omega, float _nu, int _n):
//             beta(_beta), omega(_omega), nu(_nu), n(_n),
//             S(-beta * S * I/n, 999),
//             E(beta * S * I/n - omega * E, 1),
//             I(omega * E - nu * I, 0),
//             R(nu * I, 0) {} 
// };

// struct SEIR {
//     Integrator S, E, I, R;
//     CONFIG_SEIR CSEIR;
//     SEIR(float beta, float omega, float nu, int n):
//         S(-beta * S * I/n, CSEIR.SUSCEPTIBLE), // dS(t)dt=−βS(t)I(t)N
//         E(beta * S * I/n - omega * E, CSEIR.EXPOSED), // dE(t)dt=βS(t)I(t)N−δE(t)
//         I(omega * E - nu * I, CSEIR.INFECTED), // dI(t)dt=δE(t)−νI(t)
//         R(nu * I, CSEIR.RECOVERED) {} // dR(t)dt=vI(t)
// };

// Output
// void Sample() { 
//     Print("%6.2f %g %g %g %g\n", T.Value(), seir.S.Value(), seir.E.Value(), seir.I.Value(), seir.R.Value());
// }

// Sampler Sampler(Sample, STEP);