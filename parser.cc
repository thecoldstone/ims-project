#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

#include "model.h"
#include "parser.h"

#define h

using namespace std;

void help() {
    cout << "Example: ./model --s INT [--e INT] --i INT --r INT [--d INT]\n";
    cout << "Arguments: \n" <<
            "\t-s or --s, or --susceptible INT\n" <<
            "\t-e or --e, or --exposed INT\n" <<
            "\t-i or --i, or --infected INT\n" <<
            "\t-r or --r, or --recovered INT\n";
    cout << "Possible extension: \n" <<
            "\t-beta or --beta INT (Example: --beta 5 equals to 0.05)\n" <<
            "\t-delta or --delta INT(Example: --delta 50 equals to 0.5)\n" <<
            "\t-nu or --nu INT(Example: --delta 9 equals to 0.09)\n" <<
            "\t-n or --n, or --population INT\n" <<
            "\t-l or --l, or --lockdown\n" <<
            "\t-bar or --bar\n" <<
            "\t-school or --school\n";
}

int Model::parse(int argc, char **argv) {

    int opt, tmp;
    static const char *sOptions = "s:e:i:r:n:lh:o";
    static struct option lOptions[] = {
      {"susceptible",   required_argument, 0, 's'}, // 0
      {"exposed",       required_argument, 0, 'e'}, // 1
      {"infected",      required_argument, 0, 'i'}, // 2
      {"recovered",     required_argument, 0, 'r'}, // 3
      {"population",    required_argument, 0, 'n'}, // 4
      {"beta",          required_argument, 0, 'b'}, // 5
      {"delta",         required_argument, 0, 'd'}, // 6
      {"nu",            required_argument, 0, 'u'}, // 7
      {"lockdown",      no_argument,       0, 'l'}, // 8
      {"bar",           no_argument,       0, 9},   // 9
      {"school",        no_argument,       0, 10},   // 10
      {"help",          no_argument,       0, 'h'},
      {"output",        required_argument, 0, 'o'},
      {0, 0, 0, 0}, // Avoid segmenation fault
    };

    // cout << "[+] Parse input...\n";

    while((opt = getopt_long_only(argc, argv, sOptions, lOptions, 0)) != EOF) {
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
                
                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }

                RECOVERED = tmp;
                break;
            case 'n':
                tmp = atoi(optarg);

                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }

                POPULATION = tmp;
                break;

            case 'b':
                tmp = atof(optarg);

                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }
                BETA = (tmp / 100.0);
                break;

            case 'd':
                tmp = atof(optarg);

                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }
                DELTA = (tmp / 100.0);
                break;
            
            case 'u':
                tmp = atof(optarg);

                if(tmp == -1) {
                    help();
                    return EXIT_FAILURE;
                }
                NU = (tmp / 100.0);
                break;
            case 'l':
                LOCKDOWN = 1;
                BAR = 0;
                SCHOOL = 0;
                break;
            case 9: 
                BAR = 1;
                break;
            case 10:
                SCHOOL = 1;
                break;
            case 'h':
                help();
                return EXIT_FAILURE;
            case 'o':
                OUTPUTFILE = (char*) malloc(sizeof(char)*strlen(optarg));
                strcpy(OUTPUTFILE, optarg);
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
}

// int main(int argc, char **argv) {
//     Model model = Model();
//     model.parse(argc, argv);
//     model._print();
// }