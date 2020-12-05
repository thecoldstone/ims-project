/**
 * @file parser.h
 * @brief Parser
 * @author Nikita Zhukov
 * @date 17.11.2020
 */

#ifndef _MODEL_H
#define _MODEL_H

class Model{
    public:
        Model(); // SEIR model
        void _print();
        void _S(int);
        int S();
        void _E(int);
        int E();
        void _I(int);
        int I();
        void _R(int);
        int R();
        void _N(int);
        int N();
        int parse(int, char**);
        void simulate();

    private:
        int SUSCEPTIBLE;
        int EXPOSED;
        int INFECTED;
        int RECOVERED;
        int POPULATION;

        float BETA;
        float DELTA;
        float NU;
        
        int LOCKDOWN;
        int BAR;
        int SCHOOL;
};
    
#endif