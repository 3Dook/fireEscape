/***********************************************************************************
Name: player.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/

#include "player.hpp"

Player::Player() {
	this->right = nullptr;
	this->left = nullptr;
	this->up = nullptr;
	this->down = nullptr;
	display = 'P';
}

Player::~Player() {
	// destructor
}

void Player::interaction(List *L) {
	// player will do nothing.

}

bool Player::interaction2(Item *arrayIn) {
	return true;

}