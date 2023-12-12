/**
 *   @file: othello.cc
 * @author: Hannah Culver
 *   @date: April 24, 2022
 *  @brief: implementation file for the othello class
 */

#include "colors.h"
#include "othello.h"

using namespace main_savitch_14;

void Othello::make_move(const std::string& move){

    if(move == "skip"){
        skip_flag++;
        game::make_move(move);
        return;
    }

    int column = int(toupper(move[0]) - 'A');
    int row = int(move[1] - '1');

    int stop, rstop, cstop, difference;

    int original_row = row;
    int original_column = column;

    int tmp_row = row;
    int tmp_column = column;

    char piece, opposite;

    if(moves_completed() % 2 == 0){ // X's turn
        piece = 'X';
        opposite = 'O';
    }
    else if(moves_completed() % 2 == 1){ // O's turn
        piece = 'O';
        opposite = 'X';
    }

    //if down

    for(row++; row < 8; row++){ //flipping down the board
        if(board[row][column].get_space() == piece){
            stop = row;
            difference = std::abs(stop - tmp_row) - 1;
            if(difference <= 0) break;
            for(tmp_row += 1; tmp_row < stop; tmp_row++){
                if(board[tmp_row][column].get_space() == opposite){
                    board[tmp_row][column].flip();
                }
            }
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;           //reset row
    column = tmp_column = original_column;  //reset column

    //if up

    for(row--; row >= 0; row--){ //flipping up the board
        if(board[row][column].get_space() == piece){
            stop = row;
            difference = std::abs(tmp_row - stop) - 1;
            if(difference <= 0) break;
            for(tmp_row -= 1; tmp_row > stop; tmp_row--){
                if(board[tmp_row][column].get_space() == opposite){
                    board[tmp_row][column].flip();
                }
            }
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;

    //if right

    for(column++; column < 8; column++){ //flipping along the right
        if(board[row][column].get_space() == piece){
            stop = column;
            difference = std::abs(stop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_column += 1; tmp_column < stop; tmp_column++){
                if(board[row][tmp_column].get_space() == opposite){
                    board[row][tmp_column].flip();
                }
            }
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;

    //if left

    for(column--; column >= 0; column--){ //flipping along the left
        if(board[row][column].get_space() == piece){
            stop = column;
            difference = std::abs(tmp_column - stop) - 1;
            if(difference <= 0) break;
            for(tmp_column -= 1; tmp_column > stop; tmp_column--){
                if(board[row][tmp_column].get_space() == opposite){
                    board[row][tmp_column].flip();
                }
            }
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;

    //if (+,+)

    for(row++, column++; row < 8, column < 8; row++, column++){ //flipping from top left to bottom right (+,+)
        if(board[row][column].get_space() == piece){
            rstop = row;
            cstop = column;
            difference = std::abs(rstop - tmp_row) - 1; //difference = abs(cstop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_row += 1, tmp_column += 1; tmp_row < rstop, tmp_column < cstop; tmp_row++, tmp_column++){
                if(board[tmp_row][tmp_column].get_space() == opposite){
                    board[tmp_row][tmp_column].flip();
                }
            }
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;

    //if (+,-)

    for(row++, column--; row < 8, column >= 0; row++, column--){ //flipping from top right to bottom left (+,-)
        if(board[row][column].get_space() == piece){
            rstop = row;
            cstop = column;
            difference = std::abs(rstop - tmp_row) - 1; //difference = abs(cstop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_row += 1, tmp_column -= 1; tmp_row < rstop, tmp_column > cstop; tmp_row++, tmp_column--){
                if(board[tmp_row][tmp_column].get_space() == opposite){
                    board[tmp_row][tmp_column].flip();
                }
            }
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;

    //if (-,+)

    for(row--, column++; row >= 0, column < 8; row--, column++){ //flipping from bottom left to top right (-,+)
        if(board[row][column].get_space() == piece){
            rstop = row;
            cstop = column;
            difference = std::abs(rstop - tmp_row) - 1; //difference = abs(cstop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_row -= 1, tmp_column += 1; tmp_row > rstop, tmp_column < cstop; tmp_row--, tmp_column++){
                if(board[tmp_row][tmp_column].get_space() == opposite){
                    board[tmp_row][tmp_column].flip();
                }
            }
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;

    //if (-,-)

    for(row--, column--; row >= 0, column >= 0; row--, column--){ //flipping from bottom right to top left (-,-)
        if(board[row][column].get_space() == piece){
            rstop = row;
            cstop = column;
            difference = std::abs(rstop - tmp_row) - 1; //difference = abs(cstop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_row -= 1, tmp_column -= 1; tmp_row > rstop, tmp_column > cstop; tmp_row--, tmp_column--){
                if(board[tmp_row][tmp_column].get_space() == opposite){
                    board[tmp_row][tmp_column].flip();
                }
            }
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    board[original_row][original_column].set_space(piece);
    
    flag_reset();
    game::make_move(move);
}

void Othello::restart(){

    game::restart();

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j].set_space('-');
        }
    }
    
    board[3][3].set_space('O');
    board[4][4].set_space('O');
    board[3][4].set_space('X');
    board[4][3].set_space('X');
}

game::who Othello::winning()const{

    int x = 0;
    int o = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j].get_space() == 'X') x++;
            else if(board[i][j].get_space() == 'O') o++;
        }
    }

    if(x > o) return HUMAN; //player 1
    else if(x < o) return COMPUTER; //player 2

    return NEUTRAL; // tie
}

void Othello::compute_moves(std::queue<std::string>& moves)const{

    string move;

    for(char i = 'A'; i < 'I'; i++){
        for(char j = '1'; j < '9'; j++){
            char c_column = i;
            char c_row = j;
            move = c_column;
            move += c_row;
            if(is_legal(move)){
                moves.push(move);
            }
        }
    }

    if(moves.empty()){
        moves.push("skip");
    } //add skip to queue
}

void Othello::display_status()const{

    cout << YELLOW << BOLD << "    A   B   C   D   E   F   G   H" << RESET << endl;
    cout << BOLD << "   --- --- --- --- --- --- --- ---" << endl;

    for(int i = 0; i < 7; i++){
        cout << YELLOW << BOLD << i + 1 << RESET << BOLD << " |" << RESET;
        for(int j = 0; j < 8; j++){
            cout << " ";
            board[i][j].output(cout);
            cout << BOLD << " |" << RESET;
        }
        cout << endl;
        cout << BOLD << "  |---|---|---|---|---|---|---|---|" << RESET << endl;
    }

    cout << YELLOW << BOLD << 8 << RESET << BOLD << " |" << RESET;

    for(int j = 0; j < 8; j++){
        cout << " ";
        board[7][j].output(cout);
        cout << BOLD << " |" << RESET;
    }

    cout << endl;
    cout << BOLD << "   --- --- --- --- --- --- --- ---" << RESET << endl;

    if(!is_game_over()){
        if(moves_completed() % 2 == 0){ // X's turn
            cout << "Player 1's turn" << endl;
        }
        else if(moves_completed() % 2 == 1){ // O's turn
            cout << "Player 2's turn" << endl;
        }
    }
}

int Othello::evaluate()const{

    int score = 0;
    char piece = 'O';

    //corner pieces

    if(board[0][0].get_space() == piece) score += 3;
    if(board[0][7].get_space() == piece) score += 3;
    if(board[7][0].get_space() == piece) score += 3;
    if(board[7][7].get_space() == piece) score += 3;

    //edge pieces

    for(int i = 1; i < 7; i++){
        if(board[0][i].get_space() == piece) score += 2; //top
        if(board[i][0].get_space() == piece) score += 2; //left
        if(board[i][7].get_space() == piece) score += 2; //right
        if(board[7][i].get_space() == piece) score += 2; //bottom
    }

    //other

    for(int i = 1; i < 7; i++){
        for(int j = 1; j < 7; j++){
            if(board[i][j].get_space() == piece) score += 1;
        }
    }

    return score;
}

bool Othello::is_game_over()const{

    int x = 0;
    int o = 0;

    int dash_count = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j].get_space() == 'X') x++;
            if(board[i][j].get_space() == 'O') o++;
            if(board[i][j].get_space() == '-') dash_count++;
        }
    }

    if(dash_count == 0) return true; //board is full
    else if(x == 0 || o == 0) return true; //player has no more pieces
    else if(skip_flag == 2) return true; //skips (neither player can move)

    return false;
}

bool Othello::is_legal(const std::string& move)const{

    std::queue <std::string> moves;

    if(move == "skip"){
        compute_moves(moves);
        if(moves.front() == "skip") return true;
        return false;
    }

    int column = int(toupper(move[0]) - 'A');
    int row = int(move[1] - '1');

    if(board[row][column].get_space() != '-'){
        return false; //space is already taken
    }

    int count = 0;
    int tmp_count = count;

    int stop, rstop, cstop, difference;

    int original_row = row;
    int original_column = column;

    int tmp_row = row;
    int tmp_column = column;

    char piece, opposite;

    if(moves_completed() % 2 == 0){ // X's turn
        piece = 'X';
        opposite = 'O';
    }
    else if(moves_completed() % 2 == 1){ // O's turn
        piece = 'O';
        opposite = 'X';
    }

    for(row++; row < 8; row++){ //checking down the board
        if(board[row][column].get_space() == piece){
            stop = row;
            difference = std::abs(stop - tmp_row) - 1;
            if(difference <= 0) break; //still need to check other directions
            for(tmp_row += 1; tmp_row < stop; tmp_row++){
                if(board[tmp_row][column].get_space() == opposite) tmp_count++;
            }
            if(tmp_count == difference) return true;
            break; //found first instance of current player's piece
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;           //reset row
    column = tmp_column = original_column;  //reset column
    tmp_count = count;                      //reset tmp_count

    for(row--; row >= 0; row--){ //checking up the board
        if(board[row][column].get_space() == piece){
            stop = row;
            difference = std::abs(tmp_row - stop) - 1;
            if(difference <= 0) break;
            for(tmp_row -= 1; tmp_row > stop; tmp_row--){
                if(board[tmp_row][column].get_space() == opposite) tmp_count++;
            }
            if(tmp_count == difference) return true;
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;
    tmp_count = count;

    for(column++; column < 8; column++){ //checking along the right
        if(board[row][column].get_space() == piece){
            stop = column;
            difference = std::abs(stop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_column += 1; tmp_column < stop; tmp_column++){
                if(board[row][tmp_column].get_space() == opposite) tmp_count++;
            }
            if(tmp_count == difference) return true;
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;
    tmp_count = count;

    for(column--; column >= 0; column--){ //checking along the left
        if(board[row][column].get_space() == piece){
            stop = column;
            difference = std::abs(tmp_column - stop) - 1;
            if(difference <= 0) break;
            for(tmp_column -= 1; tmp_column > stop; tmp_column--){
                if(board[row][tmp_column].get_space() == opposite) tmp_count++;
            }
            if(tmp_count == difference) return true;
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;
    tmp_count = count;

    //checking along the diagonals

    for(row++, column++; row < 8, column < 8; row++, column++){ //checking from top left to bottom right (+,+)
        if(board[row][column].get_space() == piece){
            rstop = row;
            cstop = column;
            difference = std::abs(rstop - tmp_row) - 1; //difference = abs(cstop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_row += 1, tmp_column += 1; tmp_row < rstop, tmp_column < cstop; tmp_row++, tmp_column++){
                if(board[tmp_row][tmp_column].get_space() == opposite) tmp_count++;
            }
            if(tmp_count == difference) return true;
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;
    tmp_count = count;

    for(row++, column--; row < 8, column >= 0; row++, column--){ //checking from top right to bottom left (+,-)
        if(board[row][column].get_space() == piece){
            rstop = row;
            cstop = column;
            difference = std::abs(rstop - tmp_row) - 1; //difference = abs(cstop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_row += 1, tmp_column -= 1; tmp_row < rstop, tmp_column > cstop; tmp_row++, tmp_column--){
                if(board[tmp_row][tmp_column].get_space() == opposite) tmp_count++;
            }
            if(tmp_count == difference) return true;
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;
    tmp_count = count;

    for(row--, column++; row >= 0, column < 8; row--, column++){ //checking from bottom left to top right (-,+)
        if(board[row][column].get_space() == piece){
            rstop = row;
            cstop = column;
            difference = std::abs(rstop - tmp_row) - 1; //difference = abs(cstop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_row -= 1, tmp_column += 1; tmp_row > rstop, tmp_column < cstop; tmp_row--, tmp_column++){
                if(board[tmp_row][tmp_column].get_space() == opposite) tmp_count++;
            }
            if(tmp_count == difference) return true;
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    row = tmp_row = original_row;
    column = tmp_column = original_column;
    tmp_count = count;

    for(row--, column--; row >= 0, column >= 0; row--, column--){ //checking from bottom right to top left (-,-)
        if(board[row][column].get_space() == piece){
            rstop = row;
            cstop = column;
            difference = std::abs(rstop - tmp_row) - 1; //difference = abs(cstop - tmp_column) - 1;
            if(difference <= 0) break;
            for(tmp_row -= 1, tmp_column -= 1; tmp_row > rstop, tmp_column > cstop; tmp_row--, tmp_column--){
                if(board[tmp_row][tmp_column].get_space() == opposite) tmp_count++;
            }
            if(tmp_count == difference) return true;
            break;
        }
        else if(board[row][column].get_space() == '-') break;
    }

    return false;
}

void Othello::display_moves()const{
    
    queue <string> valid_moves;
    compute_moves(valid_moves);

    cout << "---------------" << endl;
    cout << "Possible moves: " << endl;
    cout << "---------------" << endl;

    while(!valid_moves.empty()){
        cout << valid_moves.front() << endl;
        valid_moves.pop();
    }
    
    cout << "---------------" << endl;
}

//eof