#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <getopt.h>

#include "compartments.h"

using namespace std;

void parse(int argc, char **argv) {

    int opt;
    static const char *sOptions = "s:e:i:r:d";
    static struct option lOptions[] = {
      {"susceptible",   required_argument, 0, 's'},
      {"exposed",       optional_argument, 0, 'e'},
      {"infected",      required_argument, 0, 'i'},
      {"recovred",      required_argument, 0, 'r'},
      {"died",          optional_argument, 0, 'd'}  
    };

    printf("here");

    while((opt = getopt_long(argc, argv, sOptions, lOptions, nullptr)) != -1) {
        switch(opt) {
            case 0:
                printf("?");
                break;
            case 's':
                cout << opt;
                break;
            case 'e':
                cout << "e\n";
                break;
            case 'i':
                cout << "i\n";
                break;
            case 'r':
                cout << "r\n";
                break;
            case 'd':
                cout << "n\n";
                break;
            case '?':
                printf("?");
                break;
            default:
                printf("?");
                cout << "not defined character: " << opt;
        }
    }
}

int main(int argc, char **argv) {
    parse(argc, argv);
}