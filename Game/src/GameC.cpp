#include "GameC.h"
#include <iostream>
using namespace std;

char GAME_API Block::ReturValue() {
	if (value == Values::U) {
		return '_';
	}
	if (value == Values::X) {
		return 'X';
	}
	if (value == Values::O) {
		return 'O';
	}

	return '0';
}

void Game::SetValue(int  pos, Block::Values v) {

	switch (pos) {

		case 1:
			grid.p1.Is_occupied = false;
			grid.p1.value = v;
			grid.p1.Is_occupied = true;
			break;
		case 2:
			grid.p2.Is_occupied = false;
			grid.p2.value = v;
			grid.p2.Is_occupied = true;

			break;
		case 3:
			grid.p3.Is_occupied = false;
			grid.p3.value = v;
			grid.p3.Is_occupied = true;

			break;
		case 4:
			grid.p4.Is_occupied = false;
			grid.p4.value = v;
			grid.p4.Is_occupied = true;

			break;
		case 5:
			grid.p5.Is_occupied = false;
			grid.p5.value = v;
			grid.p5.Is_occupied = true;

			break;
		case 6:
			grid.p6.Is_occupied = false;
			grid.p6.value = v;
			grid.p6.Is_occupied = true;

			break;
		case 7:
			grid.p7.Is_occupied = false;
			grid.p7.value = v;
			grid.p7.Is_occupied = true;

			break;
		case 8:
			grid.p8.Is_occupied = false;
			grid.p8.value = v;
			grid.p8.Is_occupied = true;

			break;
		case 9:
			grid.p9.Is_occupied = false;
			grid.p9.value = v;
			grid.p9.Is_occupied = true;

			break;
		default:
			break;
	};
	
	
}
bool Game::Empty_checker(int  pos) {
	switch (pos) {

	case 1:
		if (grid.p1.Is_occupied == false) {
			return true;
		}
		break;
	case 2:
		if (grid.p2.Is_occupied == false) {
			return true;
		}
		break;
	case 3:
		if (grid.p3.Is_occupied == false) {
			return true;
		}
		break;
	case 4:
		if (grid.p4.Is_occupied == false) {
			return true;
		}
		break;
	case 5:
		if (grid.p5.Is_occupied == false) {
			return true;
		}
		break;
	case 6:
		if (grid.p6.Is_occupied == false) {
			return true;
		};
		break;
	case 7:
		if (grid.p7.Is_occupied == false) {
			return true;
		}
		break;
	case 8:
		if (grid.p8.Is_occupied == false) {
			return true;
		}
		break;
	case 9:
		if (grid.p9.Is_occupied == false) {
			return true;
		}
		break;
	default:

		break;
	};
	return false;
}

//---Winchecker
namespace checker {

	bool AllOccupied(Game* game) {

		
		if (game->grid.p1.Is_occupied &&
			game->grid.p2.Is_occupied &&
			game->grid.p3.Is_occupied &&
			game->grid.p4.Is_occupied &&
			game->grid.p5.Is_occupied &&
			game->grid.p6.Is_occupied &&
			game->grid.p7.Is_occupied &&
			game->grid.p8.Is_occupied &&
			game->grid.p9.Is_occupied

			) {

			return true;
		}


		return false;
	}

	
	bool Wincheck(Game* g) {

		
		                                                                                                 
		bool Won = false;
		//Check for X
		if (g->grid.p1.value == 1 && g->grid.p2.value == 1 && g->grid.p3.value == 1
			|| g->grid.p4.value == 1 && g->grid.p5.value == 1 && g->grid.p6.value == 1
			|| g->grid.p7.value == 1 && g->grid.p8.value == 1 && g->grid.p9.value == 1

			|| g->grid.p1.value == 1 && g->grid.p4.value == 1 && g->grid.p7.value == 1
			|| g->grid.p2.value == 1 && g->grid.p5.value == 1 && g->grid.p8.value == 1
			|| g->grid.p3.value == 1 && g->grid.p6.value == 1 && g->grid.p9.value == 1
			
			|| g->grid.p1.value == 1 && g->grid.p5.value == 1 && g->grid.p9.value == 1
			|| g->grid.p3.value == 1 && g->grid.p5.value == 1 && g->grid.p7.value == 1) {


			return true;
		}
		//Check for 0
		else if ((!g->grid.p1.value && !g->grid.p2.value && !g->grid.p3.value)
			|| (!g->grid.p4.value && !g->grid.p5.value && !g->grid.p6.value)
			|| (!g->grid.p7.value && !g->grid.p8.value && !g->grid.p9.value)

			|| (!g->grid.p1.value && !g->grid.p4.value && !g->grid.p7.value)
			|| (!g->grid.p2.value && !g->grid.p5.value && !g->grid.p8.value)
			|| (!g->grid.p3.value && !g->grid.p6.value && !g->grid.p9.value)
			
			|| (!g->grid.p1.value && !g->grid.p5.value && !g->grid.p9.value)
			|| (!g->grid.p3.value && !g->grid.p5.value && !g->grid.p7.value )) {

			return true;
		}
		//alternate row checking left

		return false;
	}

	

}