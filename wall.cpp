/***********************************************************************************
Name: Wall.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/

#include "wall.hpp"

Wall::Wall() {
	this->right = nullptr;
	this->left = nullptr;
	this->up = nullptr;
	this->down = nullptr;
	display = '*';
}

Wall::~Wall() {
	// destructor
}

void Wall::interaction(List *L) {
	// Wall will do nothing.
	sayLine("You can't move past a wall");
}

bool Wall::interaction2(Item *arrayIn) {
	sayLine("You can't move past a wall");
	return true;

}