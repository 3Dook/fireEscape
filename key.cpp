/***********************************************************************************
Name: key.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/

#include "key.hpp"

Key::Key() {
	this->right = nullptr;
	this->left = nullptr;
	this->up = nullptr;
	this->down = nullptr;
	display = 'K';
}

Key::~Key() {
	// destructor
}

void Key::interaction(List *L) {

	sayLine("YOU FOUND THE KEY!");
	Item *keyTool;
	keyTool = new Item;
	keyTool->setName("key");
	keyTool->setDescription("A tool to let you open the door");
	L->insertHead(keyTool);
}

bool Key::interaction2(Item *arrayIn) {
	// variables
	int choice;
	Item Key("Key", "A tool used to open the door and let you escape");

	sayLine("YOU FOUND THE KEY!!!!");

	sayLine("+++++++++++++++++++++++++++++++++++++++");
	for (int i = 0; i < 3; i++) {
		std::cout << "[" << i + 1 << "]" << arrayIn[i].getName() << " - " << arrayIn[i].getDescription() << std::endl;
	}
	sayLine("Did you want to add This item to your inventory? [1] - Yes, [2] - No");
	checkRange(choice, 1, 2);

	if (choice == 1) {
		sayLine("Please choose one slot to add The Item to...");
		sayLine("Please choose between Slots 1 tp 3");
		checkRange(choice, 1, 3);
		choice--;				// the array is 0 -2
		arrayIn[choice] = Key;			// add the key to the choice
	}
	return false;


}