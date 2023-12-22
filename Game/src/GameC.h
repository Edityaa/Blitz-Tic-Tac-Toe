#pragma once
#include "ImportHeader.h"

class GAME_API Block {

public:
	enum  Values {
		X = 1,
		O = 0,
		U = 9
	};

	bool Is_occupied = false;
	Values value = Values::U;

	char ReturValue();


	Block() {

	}

	//Reset Constructor
	Block(bool res) {
		if (res) {

			Is_occupied = false;
			value = Values::U;
		}
	}
};


class GAME_API Grid {
	
public:
	    Block p1;
		Block p2;
		Block p3;
		Block p4;
		Block p5;
		Block p6;
		Block p7;
		Block p8;
		Block p9;
		

		
};

class GAME_API Game {

public:
	Grid grid;
	bool Empty_checker(int  pos);
	void SetValue(int position, Block::Values v);

	//resetter
	void Reset() {
		grid.p1 = Block(true);
		grid.p2 = Block(true);
		grid.p3 = Block(true);
		grid.p4 = Block(true);
		grid.p5 = Block(true);
		grid.p6 = Block(true);
		grid.p7 = Block(true);
		grid.p8 = Block(true);
		grid.p9 = Block(true);

	}
};

namespace checker {
	

	bool GAME_API Wincheck(Game* g);
	bool GAME_API AllOccupied(Game* game);
	
}
