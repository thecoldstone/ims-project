#include <iostream>
#include "model.h"
#include "parser.h"
#include "simulation.h"

using namespace std;

int main(int argc, char **argv) {
    // 0. Init model
    Model model = Model();
    // 1. Parse input
    if(model.parse(argc, argv) == 1) {
        return EXIT_FAILURE;
    }
    // 2. Simulate for different scenarious
    model.simulate();

    return EXIT_SUCCESS;
}