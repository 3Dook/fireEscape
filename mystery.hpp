/***********************************************************************************
Name: mystery.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a mystery class. Which
will inherit from space.
************************************************************************************/


#include "space.hpp"
#ifndef MYSTERY_HPP
#define MYSTERY_HPP

class Mystery : public Space {

public:
	Mystery();
	~Mystery();

	// polymorphism
	void interaction(List *L);
	bool interaction2(Item *arrayIn);
};
#endif // !1
