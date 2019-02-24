//
//  Board.cpp
//  C++ 2048
//
//  Created by Ari Porad on 2019-02-24.
//  Copyright © 2019 Chocoholic Studios. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "Board.hpp"

using namespace std;

Board::Board() {
	srand((uint) time(NULL));
	addNewTile();
}

void Board::print() {
	cout << "\033[2J";
	cout << string(29, '-') << endl;
	for (auto row: board) {
		for (auto tile: row) {
			string tile_str = to_string(tile);
			leftPad(4, ' ', tile_str);
			cout << "| " << tile_str << " ";
		}
		cout << "|" << endl;
	}
	cout << string(29, '-') << endl;
}

void Board::processAction(Action action) {
	void (Board::*processMovement) (int);
	
	switch (action) {
		case Action::Up: processMovement = &Board::processUpMovement; break;
		case Action::Down: processMovement = &Board::processDownMovement; break;
		case Action::Left: processMovement = &Board::processLeftMovement; break;
		case Action::Right: processMovement = &Board::processRightMovement; break;
		default: return;
	}
	
	for (int i = 0; i < BOARD_SIZE; i++) {
		(this->*processMovement)(i);
	}
	
	checkForLoss();
	addNewTile();
}

void Board::addNewTile() {
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
		auto *pos = &board[rand() % BOARD_SIZE][rand() % BOARD_SIZE];
		if (*pos != 0) continue;
		*pos = 2;
		break;
	}
}

void Board::checkForLoss() {
	this->print();
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (board[row][col] == 0) return;
		}
	}
	std::cout << std::endl << "You have lost." << std::endl;
	exit(0);
}

void Board::processLeftMovement(int rowNum) {
	nudgeRow(rowNum);
	
	for (int i = 0; i < BOARD_SIZE - 1; i++) {
		if (board[rowNum][i] != 0 && board[rowNum][i] == board[rowNum][i + 1]) {
			board[rowNum][i] *= 2;
			board[rowNum][i + 1] = 0;
			processLeftMovement(rowNum);
			break;
		}
	}
}

void Board::processRightMovement(int rowNum) {
	std::reverse(board[rowNum].begin(), board[rowNum].end());
	processLeftMovement(rowNum);
	std::reverse(board[rowNum].begin(), board[rowNum].end());
}

void Board::processUpMovement(int columnNum) {
	nudgeColumn(columnNum);
	
	for (int i = 0; i < BOARD_SIZE - 1; i++) {
		if (board[i][columnNum] != 0 && board[i][columnNum] == board[i + 1][columnNum]) {
			board[i][columnNum] *= 2;
			board[i + 1][columnNum] = 0;
			processUpMovement(columnNum);
			break;
		}
	}
}

void Board::processDownMovement(int columnNum) {
	std::reverse(board.begin(), board.end());
	processUpMovement(columnNum);
	std::reverse(board.begin(), board.end());
}

void Board::nudgeColumn(int columnNum) {
	int nudged_idx = 0;
	for (int idx = 0; idx < BOARD_SIZE; idx++) {
		if (board[idx][columnNum] != 0) board[nudged_idx++][columnNum] = board[idx][columnNum];
	}
	for (; nudged_idx < BOARD_SIZE; nudged_idx++) {
		board[nudged_idx][columnNum] = 0;
	}
}

void Board::nudgeRow(int rowNum) {
	int nudged_idx = 0;
	for (int idx = 0; idx < BOARD_SIZE; idx++) {
		if (board[rowNum][idx] != 0) board[rowNum][nudged_idx++] = board[rowNum][idx];
	}
	for (; nudged_idx < BOARD_SIZE; nudged_idx++) {
		board[rowNum][nudged_idx] = 0;
	}

}

void Board::leftPad(int len, char pad, string &str) {
	while (str.size() < len) {
		str.insert(str.begin(), pad);
	}
}
