/***********************************************************************************
Name: grid.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a grid class
that will be use in other parts of the program an game. It will help display parts of the 
program for the user. 
************************************************************************************/


#include "space.hpp"
#include "floor.hpp"
#include "wall.hpp"
#include "door.hpp"
#include "key.hpp"
#include "mystery.hpp"
#include "player.hpp"
#include "item.hpp"
#include "fire.hpp"

class Grid {

private:
	Space ***board;
	int maxRow = 10;
	int maxCol = 10;
	// gameplay 
	int maxEnergy = 30;			// max amount of steps the player has
	int energy; // much life the player has
	//List bag;    // HUGH HEADACHE - * pointer will leader to a lot of trouble with container
	bool foundKey = false;				// Obsolete now.
	bool doorOpened = false;

	//used to hold the true key position we will hide it throughout the game
	int keyXpos;
	int keyYpos;

	Item bag2[3];			// make an array of three containers 

public:
	Grid();
	~Grid();
	//methods;
	void setGrid();					// randomize the user, key, door and miscellaneous features
	char getBDisplay(int x, int y);
	void displayGrid();

	void checkItems();			// check user inventory to determine their game State
	// linking pointers 
	void resetGridPointers();

	// gameplay functions
	void runGame();
	void randomize(Space *Z);
	void movePlayer(Space *P);
	void checkForKeySpace();

	// below are obsolete.. develop better methods to speed up the process.
	bool checkAhead(int x, int y);
	bool checkAhead2(int x, int y);
	void displayGrid2(); // Small test to attempts to read out the grid for the player.


	void move(int x, int y, Space *Z);
};


