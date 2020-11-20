#include <iostream>

#include "model.h"
#include "parser.h"
#include "simulation.h"

using namespace std;

int main(int argc, char **argv) {
    
    Model model = Model();
    // 1. Parse input
    model.parse(argc, argv);
    model._print();

    // 2. Simulate for different scenarious
    model.simulate();
}