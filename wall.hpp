/***********************************************************************************
Name: wall.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a wall class. Which
will inherit from space.
************************************************************************************/

#include "space.hpp"
#ifndef WALL_HPP
#define WALL_HPP

class Wall : public Space {

public:
	Wall();
	~Wall();

	// polymorphism
	void interaction(List *L);
	bool interaction2(Item *arrayIn);
};
#endif // !1
