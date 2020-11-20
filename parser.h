/**
 * @file parser.h
 * @brief Parser
 * @author Nikita Zhukov
 * @date 17.11.2020
 */

#ifndef _PARSER_H
#define _PARSER_H

// Default values
#define DDEAD 0

#define SSTART_TIME 0
#define SEND_TIME 100

#define STEP 0.2

// SEIR && SIR && SIRD
extern int DEAD; // D - dead

extern int POPULATION;

/**
 * @brief Shows the help information once the parser error occurs
 */
void help();
#endif