/***********************************************************************************
Name: Fire.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a Fire class. Which
will inherit from space.
will inherit from space.
************************************************************************************/

#include "space.hpp"
#ifndef FIRE_HPP
#define FIRE_HPP

class Fire : public Space {

public:
	Fire();
	~Fire();

	// polymorphism
	void interaction(List *L);
	bool interaction2(Item *arrayIn);
};
#endif // !1