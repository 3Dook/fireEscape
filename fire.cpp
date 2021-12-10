/***********************************************************************************
Name: fire.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/

#include "fire.hpp"

Fire::Fire() {
	this->right = nullptr;
	this->left = nullptr;
	this->up = nullptr;
	this->down = nullptr;
	display = 'W';
}

Fire::~Fire() {
	// destructor
}

void Fire::interaction(List *L) {
	// Fire will do nothing.
	sayLine("You can't move past a Fire");
}

bool Fire::interaction2(Item *arrayIn) {
	Item burnt("Fire", "Touched by Fire, you are dead - Game Over");

	for (int i = 0; i < 3; i++) {
		if (arrayIn[i].getName() == "Fire Suit") {
			sayLine("You are protected by the Fire Suit - you are immune to Fire");
			return false;
		}
	}

	// Game over
	sayLine("You have touched Fire, you are burnted - Game Over");
	arrayIn[1] = burnt;

	return false;
}