//
//  main.cpp
//  C++ 2048
//
//  Created by Ari Porad on 2019-02-24.
//  Copyright © 2019 Chocoholic Studios. All rights reserved.
//

#include <iostream>
#include <string>
#include "Board.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	Board board;
	InputManager inputManager;
	while (true) {
		board.print();
		board.processAction(inputManager.getAction());
	}
	return 0;
}
