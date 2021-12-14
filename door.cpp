/***********************************************************************************
Name: Door.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/

#include "door.hpp"

Door::Door() {
	this->right = nullptr;
	this->left = nullptr;
	this->up = nullptr;
	this->down = nullptr;
	display = 'O';
}

Door::~Door() {
	// destructor
}

void Door::interaction(List *L) {

	// need to check if user has key.
	if (locked) {
		sayLine("Please find the key before trying to unlock the door");
	}
	else {
		sayLine("congratulations! for successfully escaping!!!");
	}

}

bool Door::interaction2(Item *arrayIn) {
	Item OpenedDoor("Exit", "Will allow you to exit the game");

	for (int i = 0; i < 3; i++) {
		if (arrayIn[i].getName() == "Key") {
			sayLine("congratulations! for successfully escaping!!!");
			arrayIn[i] = OpenedDoor; // replace the key with the exit
			return false;
		}
	}
	// if there is no key then return true, which means the player cannot advance
	sayLine("Please find the key before trying to unlock the door");
	return true;

}