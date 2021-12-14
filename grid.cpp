/***********************************************************************************
Name: grid.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/

#include "grid.hpp"
/*
private:

public:
	Grid();
	~Grid();
	//methods;
	displayGrid();

*/
Grid::Grid() {
	// nothing for now
	// potential fix
	energy = maxEnergy;			// set max Energy into Energy 
	
	Item newItem("EMPTY SLOT", "");

	for (int i = 0; i < 3; i++) {
		bag2[i] = newItem;
	}
}



Grid::~Grid() {
// destructor
}

void Grid::setGrid() {
	board = new Space**[(maxCol+2)*(maxRow + 2)];  // 5 * 5 maybe add two later for borders


	for (int k = 0; k < ((maxCol + 2)*(maxRow + 2)); ++k) {
		board[k] = new Space*[(maxCol + 2)*(maxRow + 2)];
	}

	for (int i = 0; i < maxRow + 1; i++) {
		for (int j = 0; j < maxCol + 1; j++) {
			board[i][j] = new Floor;
		}
	}

	// make the game boarder
	for (int i = 0; i < maxCol + 2; i++) {
		board[i][0] = new Wall;
		board[i][maxCol + 1] = new Wall;
		board[0][i] = new Wall;
		board[maxRow + 1][i] = new Wall;
	}

	// below will be adding the player, the gate, the key and some mystery spots
	// decided to set it up in the game
	/* seting the pointers go through each row and set the previous right pointer to the next spaces*/
	this->resetGridPointers();
}

void Grid::resetGridPointers() {

	// seting the pointers go through each row and set the previous right pointer to the next spaces
	// go from left to right
	for (int i = 0; i < maxRow + 1; i++) {
		board[0][i]->setRight(board[0][i + 1]->getLeft());
	}

	// go from right to left
	for (int i = maxRow + 1; i > 0; i--) {
		board[0][i - 1]->setLeft(board[0][i]->getRight());
	}

	// go from up to down
	// seting the pointers go through each row and set the previous right pointer to the next spaces
	for (int i = 0; i < maxCol + 1; i++) {
		board[i][0]->setDown(board[i + 1][0]->getUp());
	}
	

	//go from down to up
	for (int i = maxCol + 1; i > 0; i--) {
		board[i - 1][0]->setUp(board[i][0]->getDown());
	}
}


char Grid::getBDisplay(int x, int y) {
	// unused.
	return board[x][y]->getSpaceDisplay();
}

void Grid::displayGrid() {
	
	std::cout << "Movement Energy Left: " << energy << std::endl;
	std::cout << "Items Found: " << std::endl;
	
	for (int i = 0; i < 3; i++) {
		std::cout << "[" << i + 1 << "]" << bag2[i].getName() <<" - "<< bag2[i].getDescription() << std::endl;
	}
	std::cout << std::endl;
	sayLine("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	for (int i = 0; i < maxRow + 2; i++) {
		for (int j = 0; j < maxCol + 2; j++) {
			std::cout << board[i][j]->getSpaceDisplay() << " ";
		}
		std::cout << "\n";
	}
}


// could be used to set 
void Grid::move(int x, int y, Space *Z){
	board[x][y] = Z;
}

void Grid::randomize(Space *Z) {
	//variables
	int xPos;
	int yPos;
	bool flag = true;

	Space *test;
	// set up the board randomly
	// set up the gate/door
	test = Z;
	while(flag){
		xPos = rand() % maxCol + 1;
		yPos = rand() % maxRow + 1;
		//aka the floor
		if (this->getBDisplay(xPos, yPos) == ' ') {
			move(xPos, yPos, test); //Set the new space here
			Z->setSpace(xPos, yPos);  // set the space 
			flag = false; // break statement
		}
	}

	if (this->getBDisplay(xPos, yPos) == 'K') {
		keyXpos = xPos;
		keyYpos = yPos;
		Z->setSpaceDisplay('?'); // hiding the k into a mystery zone
	}

}

void Grid::movePlayer(Space *P) {

	int choice;
	bool flag = true;
	int X = P->getXspace();
	int Y = P->getYspace();

	Space *temp;
	temp = new Floor;
	Item *temp2;
	temp2 = bag2;
	sayLine("Where do you want to move?");
	sayLine(" 1 = left, 2 = up, 3 = down, 4 = right");
	checkRange(choice, 1, 4);

	sayLine("++++++++++++++++++++++++++USER LOGS+++++++++++++++++++++++++++++++");

		//False means can go through through, true means you can NOT.  interactions2
		// The axis are a little mess up. I had to reedit some of the choice so it would match the user's movement.
	switch (choice) {
	case 1:
		//1 is left
	
		if (board[X][Y - 1]->interaction2(temp2)) {
			break;
		}
		else {
			move(X, (Y - 1), P); // move to new position
			move(X, Y, temp);		// replace old position
			P->setSpace(X, (Y - 1)); // set to new coordinates
		}
		break;
	case 4:
		// 4 is right
		if (board[X][Y + 1]->interaction2(temp2)) {
			break;
		}
		else {
			move(X, (Y + 1), P); // move to new position
			move(X, Y, temp);		// replace old position
			P->setSpace(X, (Y + 1)); // set to new coordinates
		}
		break;
	case 2:
		// 2 is up
		if (board[X - 1][Y]->interaction2(temp2)) {
			break;
		}
		else {
			move((X - 1), Y, P); // move to new position
			move(X, Y, temp);		// replace old position
			P->setSpace((X - 1), Y); // set to new coordinates
		}
		break;
	case 3:
		// 3 is down
		if (board[X + 1][Y]->interaction2(temp2)) {
			break;
		}
		else {
			move((X + 1), Y, P); // move to new position
			move(X, Y, temp);		// replace old position
			P->setSpace((X + 1), Y); // set to new coordinates
		}
		break;
	}

	this->checkForKeySpace(); // to ensure that there is a key space make sure the key space is on the zone or else the user may never escape
	energy--;
}




void Grid::checkForKeySpace() {

	Space *test;

	test = new Key;
	// if there is a floor space in the old key position, make sure it returns with a K spot.
	if (board[keyXpos][keyYpos]->getSpaceDisplay() == ' ') {
		move(keyXpos, keyYpos, test);
	}
	else if (board[keyXpos][keyYpos]->getSpaceDisplay() == 'W') {
		move(keyXpos, keyYpos, test);
	}


}


void Grid::checkItems() {
/* This function is critical to the state of the game. it will manage key elements of the game
and update the game status accordingly
*/
	Item newItem("EMPTY SLOT", "");

	for (int i = 0; i < 3; i++) {
		if (bag2[i].getName() == "Key") {
			foundKey = true;
		}
		else if (bag2[i].getName() == "Exit") { // Door will give this item as long as you provide it the Key it will replace the Key.
			doorOpened = true;
		}
		else if (bag2[i].getName() == "Googles") {
			if (board[keyXpos][keyYpos]->getSpaceDisplay() != 'P') {
				board[keyXpos][keyYpos]->setSpaceDisplay('K');
			}
		}
		else if (bag2[i].getName() == "Battery Charger") {
			energy++;
		}
		else if (bag2[i].getName() == "Full Charge") {
			energy = maxEnergy;
			bag2[i] = newItem;
		}
		else if (bag2[i].getName() == "Destroyed") {
			bag2[i] = newItem;
		}
		else if (bag2[i].getName() == "Fire Suit") {
		}
		else if (bag2[i].getName() == "Heavy Boots") {
			energy--;
		}
		else if (bag2[i].getName() == "Fire") {
			energy = 0; // instadeath;
		}/*
		else if (bag2[i].getName() == "Exit") {
			doorOpened = true;
		}
		*/

	}

}

void Grid::runGame(){
	//variables
	int randNumber = rand() % 100 + 1; // 1 to 100 chance
	int mysNumber = 20;
	Space *test;
	Space *user;
	Space *fire;
	Space *mystery;
	sayLine("Welcome to escape the lab\n");

	// set up the grid
	test = new Door;
	this->randomize(test);

	test = new Key;
	this->randomize(test);

	user = new Player;
	this->randomize(user);

	// creates X number of mystery spots on grid
	mystery = new Mystery;
	for (int i = 0; i < mysNumber; i++) {
		this->randomize(mystery);
	}

	// creates x number of fire spots on Grid;
	fire = new Fire;
	for (int i = 0; i < mysNumber; i++) {
		this->randomize(fire);
	}

	this->displayGrid();
	while (energy > 0) {
	
		//this->checkForKeySpace(); // make sure the key space is on the zone or else the user may never escape
		movePlayer(user);
		this->checkItems();		// Items are a huge factor to this game. It will be updated constantly to ensure everything is properly found

		// increase the difficulty by adding more mystery spots and fire.
		randNumber = rand() % 100 + 1;
		if (randNumber < 5) {
			sayLine("***LOOK OUT - The Fire is spreading!!!");
			for (int i = 0; i < 5; i++) {
				this->randomize(fire);
			}
		}
		if (randNumber > 94) {
			sayLine("***LOOK OUT - More Mystery Zones are appearing!");
			for (int i = 0; i < 7; i++) {
				this->randomize(mystery);
			}
		}

		this->displayGrid();

		if (doorOpened) {
			sayLine("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			sayLine("*****************************************************************");
			sayLine("Congratulations for escaping!!- Good job - returning to main menu");
			sayLine("*****************************************************************");
			sayLine("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			energy = 0; // just to finish the game
		}

		// use below to reset the grid pointers through out the game
		this->resetGridPointers();
	}

	sayLine("\n");
	if (!doorOpened) {
		sayLine("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		sayLine("*****************************************************************");
		sayLine("GAME OVER -It seems we got Burnted or could not escape on time - Thank you for playing");
		sayLine("*****************************************************************");
		sayLine("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	

	delete test;
	delete user;
	delete fire;
	delete mystery;
}


/******************************************************************
Below are functions that are no longer being used in the game. 
 *******************************************************************
 */
bool Grid::checkAhead(int x, int y) {
	// checking if we can just use the items array rather than linked contaienrs 
	//return board[x][y]->getSpaceDisplay();

	// finally got this to work with the interactions
	Item *temp;
	temp = bag2;

	// True means that the player can't advance false means the player will step over and into the zones

	sayLine("++++++++++++++++++++++++++USER LOGS+++++++++++++++++++++++++++++++");

	if (board[x][y]->getSpaceDisplay() == '*') {
		board[x][y]->interaction2(temp);
		return true;
	}
	else if (board[x][y]->getSpaceDisplay() == 'H') {

		if (foundKey) {
			doorOpened = true;
		}

		// if there is no key it will return true, and prevent the user from moving over, else it will let the user win and move over.
		return board[x][y]->interaction2(temp);
	}
	else if (board[x][y]->getSpaceDisplay() == 'K') {
		board[x][y]->interaction2(temp);
		/*
		Item *keyTool;//("Key", "A tool to let you open the door");
		keyTool = new Item;
		keyTool->setName("key");
		keyTool->setDescription("A tool to let you open the door");
		bag.insertHead(keyTool);
		*/
		foundKey = true;
	}


	return false;
}

void Grid::displayGrid2() {

	/**
	Attempted to design a board to will read out like a tranverse linked list. Unable to
	get it to work properly like the other labs. Will continue to use the Grid to display and
	manage player movement.
	*/

	Space *temp;

	temp = board[0][0];
	while (temp != nullptr) {
		for (int i = 0; i < maxRow + 2; i++) {
			std::cout << temp->getSpaceDisplay() << " ";
			temp = temp->getRight();
		}

	}

	for (int i = 0; i < maxRow + 2; i++) {
		for (int j = 0; j < maxCol + 2; j++) {
			std::cout << board[i][j]->getSpaceDisplay() << " ";
		}
		std::cout << "\n";
	}
}