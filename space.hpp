/***********************************************************************************
Name: space.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a space class
that will be use in other parts of the program an game. there will be virtual
function that will be inherited and override. This is an abstract class
************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime>
#include "menu.hpp"
#include "dlink.hpp"
#include "item.hpp"
class Space {

protected:
	char display;
	// pointers to adJacent squares
	Space *right;
	Space *left;
	Space *up;
	Space *down;

	// did not ultilize below in final.
	int xSpace;
	int ySpace;
public:
	// constructor and destructor
	Space();
	Space(char displayIn, Space *r, Space *l, Space *u, Space *d);
	~Space();
	void setLocation(Space *r, Space *l, Space *u, Space *d);
	char getSpaceDisplay();
	void setSpaceDisplay(char displayIn);
	// Reset Pointers
	void setRight(Space *r);
	void setLeft(Space *l);
	void setDown(Space *d);
	void setUp(Space *u);
	Space* getRight();
	Space* getLeft();
	Space* getUp();
	Space* getDown();
	int getXspace();
	int getYspace();
	void setSpace(int x, int y);
	
	//abstract
	// the interaction was glitchy and was not used in the final product
	virtual void interaction(List *L) = 0;
	virtual bool interaction2(Item *arrayIn) = 0;
	// will be used for future child class
};



#endif // Space_HPP