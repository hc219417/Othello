/**
 *   @file: space.cc
 * @author: Hannah Culver
 *   @date: April 24, 2022
 *  @brief: implementation file for the space class
 */

#include "space.h"
#include "colors.h"

void space::flip(){
    if(space == 'X'){
        space = 'O';
    }
    else if(space == 'O'){
        space = 'X';
    }
}

void space::output(ostream& outs)const{
    if(space == '-'){
        outs << BLUE << BOLD << '-' << RESET;
    }
    else if(space == 'X'){
        outs << RED << BOLD << 'X' << RESET;
    }
    else if(space == 'O'){
        outs << CYAN << BOLD << 'O' << RESET;
    }
}