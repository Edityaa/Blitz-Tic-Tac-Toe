#include <iostream>
using namespace std;
#include "App.h"

enum Turn {

	X = 1,
	O = 0
};

int main() {

	std::cout << "Welcome To Tic Tac Toe " << std::endl;

	//--Make Game
	Game* game = new Game;

	unsigned int Input=999;
	unsigned int Turn = Turn::O;
	bool Quit = false;

	while (!Quit) {

		//--Print grid
		cout << game->grid.p1.ReturValue() << " + "
			<< game->grid.p2.ReturValue() << " + "
			<< game->grid.p3.ReturValue() << endl;
		cout << game->grid.p4.ReturValue() << " + "
			<< game->grid.p5.ReturValue() << " + "
			<< game->grid.p6.ReturValue() <<endl;
		cout << game->grid.p7.ReturValue() << " + "
			<< game->grid.p8.ReturValue() << " + "
			<< game->grid.p9.ReturValue() << endl;
		
		//Game Won Checker
		
		if (checker::Wincheck(game)) {
			//Game won
			cout << ((Turn == Turn::X) ? ('0') : ('X')) << " won the game!!" << endl;
			break;
		}
		//Tie Checker
		if (checker::AllOccupied(game)) {
			cout << "Its a tie " << endl;

			delete game;
			Quit = false;
			break;
		}
		

		//---taking Input
		TakeInput(&Turn,&Input);
		

		//Check for Exit
		if (Input == 20) {
			game->Reset();
			continue;
		}

		//Check foe Quit
		if (Input == 30) {
			exit(0);
		}

		//--Set val and Empty Checker

		if (Turn == Turn::X && game->Empty_checker(Input)) {
			game->SetValue(Input, (Block::Values)Turn::X );
		}
		else if (Turn == Turn::O && game->Empty_checker(Input)) {
			game->SetValue(Input, (Block::Values)Turn::O);
		}
		else {
			cout << "------------------------" << endl;
			cout << "Invalid "<<endl;
			cout << "------------------------" << endl;
			continue;
		}

		//--Turn Swapper
		if (Turn == Turn::X) {
			Turn = Turn::O;
		}
		else if (Turn == Turn::O) {
			Turn = Turn::X;
		}
		else {
			cout << "Invalid Input" << endl;
		}


	}

	delete game;
	return 0;
}

void TakeInput(unsigned int * Turn,unsigned int* Input) {
	cout << "----------------------------------" << endl;
	cout << "20 to Reset " << endl;
	cout << "30 to QUIT " << endl;
	cout << "Enter Choice " << ((*Turn) ? ('X') : ('O')) << " Chance::" << endl;;
	cout << "------------------------------" << endl;
	cin >> *Input;
	cout << "------------------------------" << endl;

}