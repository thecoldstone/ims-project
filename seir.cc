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

void SEIR::setParameters(int _n, int lockdown) {
    if(lockdown == 1){  
        beta = (roundf((1.0 * ((((float) rand()) / (float) RAND_MAX)) + 0.0) * 100 ) /100) * 0.7;
    } else {
        beta = (roundf((1.0 * ((((float) rand()) / (float) RAND_MAX)) + 0.0) * 100 ) /100);
    }
    delta =     roundf((1.0 * ((((float) rand()) / (float) RAND_MAX)) + 0.0) * 100) /100;
    nu =        roundf((1.0 * ((((float) rand()) / (float) RAND_MAX)) + 0.0) * 100 ) /100;
    n =         _n;
}

void SEIR::sample() {
    Print("%6.2f %g %g %g %g\n", 
        T.Value(), 
        S.Value(), 
        E.Value(), 
        I.Value(), 
        R.Value());
}