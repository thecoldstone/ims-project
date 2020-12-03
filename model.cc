#include <iostream>
#include "model.h"
#include "default.h"

using namespace std;

Model::Model() {
    SUSCEPTIBLE = DSUSCEPTIBLE;
    EXPOSED = DEXPOSED;
    INFECTED = DINFECTED;
    RECOVERED = DRECOVERED;
    POPULATION = DPOPULATION;
    LOCKDOWN = DLOCKDOWN;
}

Model::Model(int S, int E, int I, int R) {
    SUSCEPTIBLE = S;
    EXPOSED = E;
    INFECTED = I;
    RECOVERED = R;
}

Model::Model(int S, int I, int R) {
    // TODO
}

Model::Model(int S, int E, int I, int R, int D) {
    // TODO
}

void Model::_print() {
    cout << "S = " << SUSCEPTIBLE << "\n";
    cout << "E = " << EXPOSED << "\n";
    cout << "I = " << INFECTED << "\n";
    cout << "R = " << RECOVERED << "\n";
    cout << "P = " << POPULATION << "\n";
}

void Model::_S(int s) {
    if (s > 0) {
        SUSCEPTIBLE = s;
    }
}

int Model::S() {
    return SUSCEPTIBLE;
}

void Model::_E(int e) {
    if (e > 0) {
        EXPOSED = e;
    }
}

int Model::E() {
    return EXPOSED;
}

void Model::_I(int i) {
    if (i > 0) {
        INFECTED = i;
    }
}

int Model::I() {
    return INFECTED;
}

void Model::_R(int r) {
    if (r > 0) {
        RECOVERED = r;
    }
}

int Model::R() {
    return RECOVERED;
}

void Model::_N(int n) {
    if (n > 0) {
        POPULATION = n;
    }
}

int Model::N(){
    return POPULATION;
}
