#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <getopt.h>

#include "parser.h"

using namespace std;

int SUSCEPTIBLE = DSUSCEPTIBLE;
int EXPOSED = DEXPOSED;
int INFECTED = DINFECTED;
int RECOVERED = DRECOVERED; 
int DEAD = DDEAD;
int POPULATION = N;

void help() {
    cout << "Example: ./model --s INT [--e INT] --i INT --r INT [--d INT]\n";
    cout << "Arguments: \n" <<
            "\t-s or --s, or --susceptible INT\n" <<
            "\t-e or --e, or --exposed INT\n" <<
            "\t-i or --i, or --infected INT\n" <<
            "\t-r or --r, or --recovered INT\n" <<
            "\t-d or --d, or --dead INT\n";
    // cout << "Possible extension: \n" <<
    //         "\t-n or --n, or --population INT\n";
    
}

int parse(int argc, char **argv) {

    int opt;
    static const char *sOptions = "s:e:i:r:d"; // n
    static struct option lOptions[] = {
      {"susceptible",   required_argument, 0, 's'},
      {"exposed",       required_argument, 0, 'e'},
      {"infected",      required_argument, 0, 'i'},
      {"recovered",     required_argument, 0, 'r'},
      {"dead",          required_argument, 0, 'd'},
    //   {"population",    required_argument, 0, 'n'},
      {nullptr, 0, nullptr, 0}, // Avoid segmenation fault
    };

    while((opt = getopt_long(argc, argv, sOptions, lOptions, nullptr)) != EOF) {
        // printf("%c\n", opt);
        switch(opt) {
            case 0:

                break;
            case 's':
                SUSCEPTIBLE = atoi(optarg);
                
                // Handling invalid argument
                if(SUSCEPTIBLE == 0) {
                    help();
                    return EXIT_FAILURE;
                }

                break;
            case 'e':
                
                EXPOSED = atoi(optarg);
                
                // Handling invalid argument
                if(EXPOSED == 0) {
                    help();
                    return EXIT_FAILURE;
                }

                break;
            case 'i':

                if(optarg == nullptr) {
                    help();
                    return EXIT_FAILURE;
                }
                INFECTED = atoi(optarg);
                
                // Handling invalid argument
                if(INFECTED == 0) {
                    help();
                    return EXIT_FAILURE;
                }
                
                break;
            case 'r':
                
                RECOVERED = atoi(optarg);
                
                // Handling invalid argument
                if(RECOVERED == 0) {
                    help();
                    return EXIT_FAILURE;
                }
                
                break;
            case 'd':
                
                DEAD = atoi(optarg);
                
                // Handling invalid argument
                if(DEAD == 0) {
                    help();
                    return EXIT_FAILURE;
                }
                
                break;

            // case 'n':

            //     POPULATION = atoi(optarg);

            //     // Handling invalid argument
            //     if(POPULATION == 0) {
            //         help();
            //         return EXIT_FAILURE;
            //     }
                
            //     break;


            case '?':
                break;

            default:
                help();
                return EXIT_FAILURE;
        }
    }

    if (optind <= 1) {
        help();
        return EXIT_FAILURE;
    }

    // cout << SUSCEPTIBLE << ' ' << EXPOSED << ' ' << INFECTED << ' ' << RECOVERED << ' ' << DEAD << ' ' << POPULATION;

    return EXIT_SUCCESS;
}

// int main(int argc, char **argv) {
//     parse(argc, argv);
// }