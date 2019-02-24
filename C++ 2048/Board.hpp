//
//  Board.hpp
//  C++ 2048
//
//  Created by Ari Porad on 2019-02-24.
//  Copyright © 2019 Chocoholic Studios. All rights reserved.
//

#pragma once
#include <array>
#include <string>
#include "InputManager.hpp"

#define BOARD_SIZE 4

using namespace std;

class Board {
public:
	Board();
	void processAction(Action action);
	void print();
	
private:
	using Row = array<uint16_t, BOARD_SIZE>;
	
	array<Row, BOARD_SIZE> board;
	void processRightMovement(int rowNum);
	void processLeftMovement(int rowNum);
	void processUpMovement(int columnNum);
	void processDownMovement(int columnNum);
	void nudgeRow(int rowNum);
	void nudgeColumn(int columnNum);
	
	void checkForLoss();
	
	void addNewTile();
	
	void leftPad(int len, char pad, string &str);
};

