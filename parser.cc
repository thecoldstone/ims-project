#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <getopt.h>

#include "model.h"
#include "parser.h"

using namespace std;

void help() {
    cout << "Example: ./model --s INT [--e INT] --i INT --r INT [--d INT]\n";
    cout << "Arguments: \n" <<
            "\t-s or --s, or --susceptible INT\n" <<
            "\t-e or --e, or --exposed INT\n" <<
            "\t-i or --i, or --infected INT\n" <<
            "\t-r or --r, or --recovered INT\n" <<
            "\t-d or --d, or --dead INT\n";
    cout << "Possible extension: \n" <<
            "\t-n or --n, or --population INT\n";    
}

int Model::parse(int argc, char **argv) {

    int opt, tmp;
    static const char *sOptions = "s:e:i:r:d:n:"; // n
    static struct option lOptions[] = {
      {"susceptible",   required_argument, 0, 's'},
      {"exposed",       required_argument, 0, 'e'},
      {"infected",      required_argument, 0, 'i'},
      {"recovered",     required_argument, 0, 'r'},
      {"dead",          required_argument, 0, 'd'},
      {"population",    required_argument, 0, 'n'},
      {nullptr, 0, nullptr, 0}, // Avoid segmenation fault
    };

    cout << "[+] Parser...\n";

    while((opt = getopt_long(argc, argv, sOptions, lOptions, nullptr)) != EOF) {
        // printf("%c\n", opt);
        switch(opt) {
            case 0:

                break;
            case 's':
                tmp = atoi(optarg);
                
                // Handling invalid argument
                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }

               SUSCEPTIBLE = tmp;

                break;
            case 'e':
                
                tmp = atoi(optarg);
                
                // Handling invalid argument
                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }

                EXPOSED = tmp;

                break;
            case 'i':

                tmp = atoi(optarg);

                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }

                INFECTED = tmp;
                
                break;
            case 'r':
                
                tmp = atoi(optarg);
                
                // Handling invalid argument
                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }

                RECOVERED = tmp;
                
                break;
            case 'd':
                
                tmp = atoi(optarg);
                
                // Handling invalid argument
                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }

                // DEAD = tmp;
                
                break;

            case 'n':

                tmp = atoi(optarg);

                // Handling invalid argument
                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }

                POPULATION = tmp;
                
                break;


            case '?':
                break;

            default:
                help();
                return EXIT_FAILURE;
        }
    }

    if (optind < 1) {
        help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
    // cout << SUSCEPTIBLE << ' ' << EXPOSED << ' ' << INFECTED << ' ' << RECOVERED << ' ' << DEAD << ' ' << POPULATION;
}

// int main(int argc, char **argv) {
//     parse(argc, argv);
// }