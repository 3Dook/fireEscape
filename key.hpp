/***********************************************************************************
Name: key.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a key class. Which
will inherit from space.
************************************************************************************/

#include "space.hpp"
#ifndef KEY_HPP
#define KEY_HPP

class Key : public Space {

public:
	Key();
	~Key();

	// polymorphism
	void interaction(List *L);
	bool interaction2(Item *arrayIn);
};
#endif // !1
