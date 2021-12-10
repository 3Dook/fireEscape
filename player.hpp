/***********************************************************************************
Name: Player.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a Player class. Which
will inherit from space.
************************************************************************************/

#include "space.hpp"
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player : public Space {

private:
	
public:
	Player();
	~Player();

	// polymorphism
	void interaction(List *L);
	bool interaction2(Item *arrayIn);
};
#endif // !1
