/**
 *   @file: space.h
 * @author: Hannah Culver
 *   @date: April 24, 2022
 *  @brief: header file for the space class
 */

#ifndef SPACE_H
#define SPACE_H

#include <iostream>
using namespace std;

class space{
    public:
        void flip();
        void set_space(char s) {space = s;}
        char get_space()const {return space;}
        void output(ostream& outs)const;
    private:
        char space;
};

#endif