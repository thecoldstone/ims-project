/**
 * @file parser.h
 * @brief Parser
 * @author Nikita Zhukov
 * @date 17.11.2020
 */

#ifndef _PARSER_H
#define _PARSER_H

// Default values
#define DSUSCEPTIBLE 999
#define DEXPOSED 1
#define DINFECTED 0
#define DRECOVERED 0
#define DDEAD 0

#define SSTART_TIME 0
#define SEND_TIME 100

#define STEP 0.2

// SEIR && SIR && SIRD
extern int SUSCEPTIBLE; // S - susceptible
extern int EXPOSED; // E - exposed
extern int INFECTED; // I - infected
extern int RECOVERED; // R - recovered (removed)
extern int DEAD; // D - dead

/**
 * @brief Shows the help information once the parser error occurs
 */
void help();

/**
 * @brief Parse input arguments
 * @param argc - number of arguments
 * @param argv - buffer containing arguments 
 */ 
int parse(int argc, char** argv);

#endif