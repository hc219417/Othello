/**
 *   @file: othello.h
 * @author: Hannah Culver
 *   @date: April 24, 2022
 *  @brief: header file for the othello class
 */

#ifndef OTHELLO_H
#define OTHELLO_H

#include "game.h"
#include "space.h"

namespace main_savitch_14
{
    class Othello:public game{
        public:
            Othello() {skip_flag = 0;}
            void flag_reset() {skip_flag = 0;}

            void make_move(const std::string& move);
            void restart();

            who winning()const;

            game* clone()const {return new Othello(*this);}
            void compute_moves(std::queue<std::string>& moves)const;
            void display_status()const;
            int evaluate()const;
            bool is_game_over()const;
            bool is_legal(const std::string& move)const;

            void display_moves()const;
        private:
            space board[8][8];
            mutable int skip_flag;
    };
}

#endif