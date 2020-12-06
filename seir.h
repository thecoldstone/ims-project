#ifndef _SEIR_H
#define _SEIR_H

#include "simlib.h"

class SEIR  {
    public :
        Parameter beta, delta, nu, n;
        Integrator S, E, I, R;
        SEIR(float _beta, float _delta, float _nu, int _n):
            beta(_beta), delta(_delta), nu(_nu), n(_n),
            S((-beta * S * I)/n),
            E((beta * S * I)/n - delta * E),
            I(delta * E - nu * I),
            R(nu * I) {} 

            void setIntegrators(int _S, int _E, int _I, int _R);
            void setParameters(float _beta, float _delta, float _nu, int _n, int lockdown, int bar, int school);
            void sample();
            void printParameters();
};

#endif