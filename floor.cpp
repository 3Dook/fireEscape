/***********************************************************************************
Name: floor.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/

#include "floor.hpp"

Floor::Floor() {
	this->right = nullptr;
	this->left = nullptr;
	this->up = nullptr;
	this->down = nullptr;
	display = ' ';
}

Floor::~Floor() {
	// destructor
}

void Floor::interaction(List *L) {
	// floor will do nothing.

}

bool Floor::interaction2(Item *arrayIn) {
	return false;

}