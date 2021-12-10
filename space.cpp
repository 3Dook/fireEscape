/***********************************************************************************
Name: space.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/

#include "space.hpp"
/*

protected:
	char display;
	// pointers to adJacent squares
	Space *right;
	Space *left;
	Space *up;
	Space *down;

public:
	// constructor and destructor
	Space();
	Space(char displayIn, Space *r, Space *l, Space *u, Space *d);
	~Space();
	void setLocation(Space *r, Space *l, Space *u, Space *d);

};
*/

Space::Space() {
	this->right = nullptr;
	this->left = nullptr;
	this->up = nullptr;
	this->down = nullptr;
	display = ' ';
	xSpace = 0;
	ySpace = 0;
}
Space::Space(char displayIn, Space *r, Space *l, Space *u, Space *d) {
	this->right = r;
	this->left = l;
	this->up = u;
	this->down = d;
	display = displayIn;
}
Space::~Space() {

}

// methods
void Space::setLocation(Space *r, Space *l, Space *u, Space *d) {
	this->right = r;
	this->left = l;
	this->up = u;
	this->down = d;
}
// Reset Pointers // up able to figure out how to reset link up pointers
void Space::setRight(Space *r){
	right = r;
}
void Space::setLeft(Space *l){
	left = l;
}
void Space::setDown(Space *d){
	down = d;
}
void Space::setUp(Space *u){
	up = u;
}

Space* Space::getRight() {
	return right;
}
Space* Space::getLeft() {
	return left;
}
Space* Space::getUp() {
	return up;
}
Space* Space::getDown() {
	return down;
}



char Space::getSpaceDisplay() {
	return this->display;
}
void Space::setSpaceDisplay(char displayIn) {
	display = displayIn;
}

int Space::getXspace() {
	return xSpace;
}
int Space::getYspace() {
	return ySpace;
}
void Space::setSpace(int x, int y) {
	xSpace = x;
	ySpace = y;
}