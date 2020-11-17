#ifndef _PARSER_H
#define _PARSER_H

#define DEFAULT_SUSCEPTIBLE 999
#define DEFAULT_EXPOSED 1
#define DEFAULT_INFECTED 0
#define DEFAULT_RECOVERED 0
#define DEFAULT_DEAD 0

// SEIR && SIR && SIRD
int S; // S - susceptible
int E; // E - exposed
int I; // I - infected
int R; // R - recovered (removed)
int D; // D - dead

/**
 */
void help();

/**
 */ 
int parse(int, char**);

#endif