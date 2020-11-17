#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <getopt.h>

#include "parser.h"

using namespace std;

void help() {
    cout << "Example: ./model --s INT [--e INT] --i INT --r INT [--d INT]\n";
    cout << "Argumets: \n" <<
            "\t-s or --s, or --susceptible INT\n" <<
            "\t-e or --e, or --exposed INT\n" <<
            "\t-i or --i, or --infected INT\n" <<
            "\t-r or --r, or --recovred INT\n" <<
            "\t-d or --d, or --died INT\n";
}

int parse(int argc, char **argv) {

    int opt;
    static const char *sOptions = "s:e:ir:d";
    static struct option lOptions[] = {
      {"susceptible",   required_argument, nullptr, 's'},
      {"exposed",       required_argument, nullptr, 'e'},
      {"infected",      required_argument, nullptr, 'i'},
      {"recovred",      required_argument, nullptr, 'r'},
      {"died",          required_argument, nullptr, 'd'},
      {nullptr, 0, nullptr, 0} // Avoid segmenation fault
    };

    while((opt = getopt_long(argc, argv, sOptions, lOptions, nullptr)) != -1) {
        switch(opt) {
            case 0:
                printf("0");
                break;
            case 's':
                S = atoi(optarg);
                
                // Handling invalid argument
                if(S == 0) {
                    help();
                    return EXIT_FAILURE;
                }

                break;
            case 'e':
                
                E = atoi(optarg);
                
                // Handling invalid argument
                if(E == 0) {
                    help();
                    return EXIT_FAILURE;
                }

                break;
            case 'i':

                I = atoi(optarg);
                
                // Handling invalid argument
                if(I == 0) {
                    help();
                    return EXIT_FAILURE;
                }
                
                break;
            case 'r':
                
                R = atoi(optarg);
                
                // Handling invalid argument
                if(R == 0) {
                    help();
                    return EXIT_FAILURE;
                }
                
                break;
            case 'd':
                
                D = atoi(optarg);
                
                // Handling invalid argument
                if(D == 0) {
                    help();
                    return EXIT_FAILURE;
                }
                
                break;
            case '?':
            default:
                help();
                return EXIT_FAILURE;
        }
    }

    if (optind <= 1) {
        help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// int main(int argc, char **argv) {
//     parse(argc, argv);
// }