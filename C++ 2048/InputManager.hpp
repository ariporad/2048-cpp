//
//  InputManager.hpp
//  C++ 2048
//
//  Created by Ari Porad on 2019-02-24.
//  Copyright © 2019 Chocoholic Studios. All rights reserved.
//

#pragma once

enum class Action {
	Up, Down, Left, Right
};

class InputManager {
public:
	Action getAction();
};
