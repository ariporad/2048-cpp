//
//  InputManager.cpp
//  C++ 2048
//
//  Created by Ari Porad on 2019-02-24.
//  Copyright © 2019 Chocoholic Studios. All rights reserved.
//

#include <iostream>
#include "InputManager.hpp"

Action InputManager::getAction() {
	char input;
	std::cin.get(input);
	
	switch (input) {
		case ',': return Action::Up;
		case 'o': return Action::Down;
		case 'a': return Action::Left;
		case 'e': return Action::Right;
		default: return getAction();
	}
}
