/*************************************************************************
	This is a sample of what the main should like for the third phase of 
	the Othello game. The only change is that the game now tells 
	the human whether or not they have won.

	John Dolan	Ohio University		Fall 2019
*************************************************************************/

#include <iostream>
#include "othello.h"

using namespace std;
using namespace main_savitch_14;

int main(){

	Othello mygame;
	game::who winner;
	winner = mygame.play();

	if(winner == game::HUMAN){
		cout << "YOU WIN!" << endl;
	}
	else if(winner == game::COMPUTER){
		cout << "YOU LOSE!" << endl;
	}
	else cout << "DRAW!" << endl;

	return 0;
}