/***********************************************************************************
Name: floor.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a floor class. Which 
will inherit from space. 
************************************************************************************/

#include "space.hpp"
#ifndef FLOOR_HPP
#define FLOOR_HPP

class Floor : public Space {

public:
	Floor();
	~Floor();

	// polymorphism
	void interaction(List *L);
	bool interaction2(Item *arrayIn);
};
#endif // !1

