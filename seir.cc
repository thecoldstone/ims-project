#include <iostream>
#include "seir.h"

using namespace std;

void SEIR::setIntegrators(int _S, int _E, int _I, int _R) {
    S.Init(_S);
    E.Init(_E);
    I.Init(_I);
    R.Init(_R);
}

void SEIR::setParameters(float _beta, float _delta, float _nu, int _n) {
    beta = _beta;
    delta = _delta;
    nu = _nu;
    n = _n; // Population parameter
}

// void SEIR::printParameters() {
//     cout << "S = " << S.Value() << "\n";
//     cout << "E = " << DE << "\n";
//     cout << "I = " << DI << "\n";
//     cout << "R = " << DR << "\n";
//     cout << "P = " << DP << "\n";
// }