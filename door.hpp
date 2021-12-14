/***********************************************************************************
Name: door.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a door class. Which
will inherit from space.
************************************************************************************/


#include "space.hpp"
#ifndef DOOR_HPP
#define DOOR_HPP

class Door : public Space {

private:
	bool locked = true; // no longer used for gameplay
public:
	Door();
	~Door();

	// polymorphism
	void interaction(List *L);
	bool interaction2(Item *arrayIn);
};
#endif // !1
