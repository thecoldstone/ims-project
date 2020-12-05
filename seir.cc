#include <iostream>
#include <math.h>
#include "seir.h"

using namespace std;

void SEIR::setIntegrators(int _S, int _E, int _I, int _R) {
    S.Init(_S);
    E.Init(_E);
    I.Init(_I);
    R.Init(_R);
}

void SEIR::setParameters(float _beta, float _delta, float _nu, int _n, int lockdown, int bar, int school) {
    float tmpVal = _beta;
    if(bar == 1) {
        tmpVal = _beta * 3; 
    }
    if(school == 1) {
        tmpVal = tmpVal + _beta*1.5;
    }
    if(lockdown == 1) {
        tmpVal = _beta * 0.7;
    }
    
    beta = tmpVal;    
    // cout << "Beta = " << beta.Value() << "\n";

    delta = _delta;
    nu = _nu;

    n = _n;
    // cout << "Population =" << n.Value() << "\n";
}

void SEIR::sample() {
    Print("%6.2f %g %g %g %g\n", 
        T.Value(), 
        S.Value(), 
        E.Value(), 
        I.Value(), 
        R.Value());
}