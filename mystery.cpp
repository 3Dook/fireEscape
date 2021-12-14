/***********************************************************************************
Name: mystery.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/

#include "mystery.hpp"

Mystery::Mystery() {
	this->right = nullptr;
	this->left = nullptr;
	this->up = nullptr;
	this->down = nullptr;
	display = '?';
}

Mystery::~Mystery() {
	// destructor
}

void Mystery::interaction(List *L) {
	// mystery will do nothing.

}

bool Mystery::interaction2(Item *arrayIn) {
	/* List of potential items
	1. Googles
	2. Battery Charger
	3. Full Charge
	4. Fire Suit
	5. Destroyed
	6. Heavy Boots
	*/
	int randNum = rand() % 6 + 1; // should be 1 to 6
	int choice;
	Item newItem;

	sayLine("YOU HAVE ENTERED THE MYSTERY ZONE!!!!");
	sayLine("????????????????????????????????????????????");
	sayLine("Item List: *Curent* ");
	for (int i = 0; i < 3; i++) {
		std::cout << "[" << i + 1 << "]" << arrayIn[i].getType() << std::endl;
	}
	sayLine("--------------------------------------------");
	choice = randNum;

	switch (choice)
	{
	case 1:
		sayLine("YOU FOUND GOOGLES - glasses to help you locate the Key!!!!");
		sayLine("Did you want to add This item to your inventory? [1] - Yes, [2] - No");
		checkRange(choice, 1, 2);

		if (choice == 1) {
			newItem.setName("Googles");
			newItem.setDescription("An item that will reveal the location of the Key");
			sayLine("Please choose one slot to add The Item to...");
			sayLine("Please choose between Slots 1 tp 3");
			checkRange(choice, 1, 3);
			choice--;				// the array is 0 -2
			arrayIn[choice] = newItem;			// add the key to the choice
		}
		break;
	case 2:
		sayLine("YOU FOUND a Charger - This item helps give you more energy with each step!!!");
		sayLine("Did you want to add This item to your inventory? [1] - Yes, [2] - No");
		checkRange(choice, 1, 2);

		if (choice == 1) {
			newItem.setName("Battery Charger");
			newItem.setDescription("An item that will give you one extra step per step ");
			sayLine("Please choose one slot to add The Item to...");
			sayLine("Please choose between Slots 1 tp 3");
			checkRange(choice, 1, 3);
			choice--;				// the array is 0 -2
			arrayIn[choice] = newItem;			// add the key to the choice
		}
		break;
	case 3:
		sayLine("YOU FOUND a FULL CHARGER (IMMEDIATE ONE USE) - This item will reset you back to the max steps, use with caution");
		sayLine("Did you want to add This item to your inventory? [1] - Yes, [2] - No");
		checkRange(choice, 1, 2);

		if (choice == 1) {
			newItem.setName("Full Charge");
			newItem.setDescription("An item that will immediately reset you back to the original maxSteps");
			sayLine("Please choose one slot to add The Item to...");
			sayLine("Please choose between Slots 1 tp 3");
			checkRange(choice, 1, 3);
			choice--;				// the array is 0 -2
			arrayIn[choice] = newItem;			// add the key to the choice
		}
		break;
	case 4:
		sayLine("*CURSED ITEM - a Random Item will be Destroyed from your inventory");
		randNum = rand() % 3 + 1;
		newItem.setName("Destroyed");
		newItem.setDescription("An item is randomly Destroyed");
		randNum--;					// decrease it back to 0 -2;
		arrayIn[randNum] = newItem;

		break;
	case 5:
		sayLine("YOU FOUND a Fire Suit - Grants immunity and allows you to walk through Fire!!");
		sayLine("Did you want to add This item to your inventory? [1] - Yes, [2] - No");
		checkRange(choice, 1, 2);

		if (choice == 1) {
			newItem.setName("Fire Suit");
			newItem.setDescription("A Suit that gives you immunity to fire");
			sayLine("Please choose one slot to add The Item to...");
			sayLine("Please choose between Slots 1 tp 3");
			checkRange(choice, 1, 3);
			choice--;				// the array is 0 -2
			arrayIn[choice] = newItem;			// add the key to the choice
		}
		break;
	case 6:
		sayLine("*CURSED ITEM - a Random Item will be replaced from your inventory");
		randNum = rand() % 3 + 1;
		newItem.setName("Heavy Boots");
		newItem.setDescription("These boots are so heavy, that it takes more energy to move");
		randNum--;					// decrease it back to 0 -2;
		arrayIn[randNum] = newItem;

		break;
	}




	return false;

}