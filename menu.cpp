/***************************************************************************
Name: menu.cpp
Author : Duc Doan
Date : 2 / 24 / 2019
Description : This is a menu cpp file. It contains helpful and useful methods
to develop and add in running our programs. 

************************************************************************************/

#include "menu.hpp"

void Menu::runProgram() {
	// USE ONLY IF WE NEED TO RUN A PROGRAM IN MAIN.
	//system("pause");

}

void Menu::prompt(int choiceIn) {


	// The following are prompts that will be called out when ran.
	/*
	// initial prompt //
	std::string name = "NAME HOLDER ";
	std::string description = "Description Holder";
	std::string rules = "RULES HOLDER";

	switch (choiceIn) {
	case 0:
		std::cout << "Hello! Did you want to play a game called " << name << std::endl;
		break;
	case 1:
		// introduction 
		std::cout << "Great! It simple, the game is play as " << description << std::endl;
		break;
	case 2:
		//rules
		std::cout << "Rules and Information:: " << rules << std::endl;
		break;
	case 3:
		//Game Over
		std::cout << "GAME OVER\n";
		break;
	case 4:
		//Play again?
		std::cout << "Did you want to play again or Quit?\n";
		break;
	case 5:
		// Good bye
		std::cout << "I hope you had fun, Good bye!\n";
		break;
	}

	*/
	std::string name = "NAME HOLDER ";
	std::string description = "Description Holder";
	std::string rules = "RULES HOLDER";

	switch (choiceIn) {
	case 0:
		std::cout << "Hello! Did you want to play a game called " << name << std::endl;
		break;
	case 1:
		// introduction 
		std::cout << "Great! It simple, the game is play as " << description << std::endl;
		break;
	case 2:
		//rules
		std::cout << "Rules and Information:: " << rules << std::endl;
		break;
	case 3:
		//Game Over
		std::cout << "GAME OVER\n";
		break;
	case 4:
		//Play again?
		std::cout << "Did you want to play again or Quit?\n";
		break;
	case 5:
		// Good bye
		std::cout << "I hope you had fun, Good bye!\n";
		break;
	}

}

// this function will display a menu for the user to choose between.
void Menu::display() {

	/*
	std::string option1 = "";
	std::string option2 = "";
	std::string option3 = "";
	std::string option4 = "";
	std::string option5 = "";

	std::cout << "------------------------------MENU-----------------------------" << std::endl;
	std::cout << "Please pick from the following MENU Options" << std::endl;
	std::cout << "[1] " << option1 << std::endl;
	std::cout << "[2] " << option2 << std::endl;
	std::cout << "[3] " << option3 << std::endl;
	*/

	std::string option1 = "INTRODUCTION AND RULES";
	std::string option2 = "PLAY GAME";
	std::string option3 = "EXIT";
	std::string option4 = "";
	std::string option5 = "";

	std::cout << "------------------------------MENU-----------------------------" << std::endl;
	std::cout << "Please pick from the following MENU Options" << std::endl;
	std::cout << "[1] " << option1 << std::endl;
	std::cout << "[2] " << option2 << std::endl;
	std::cout << "[3] " << option3 << std::endl;
}

void Menu::rules() {
	std::cout << "------------------------------RULES----------------------------" << std::endl;
	sayLine("Synopsis: You are a sentient Robot in a super villian's Lab.   ");
	sayLine("The lab has caught on fire, and you need to escape the room you");
	sayLine("are trap in. To escape the room you must find the key to the   ");
	sayLine("Door. Because you just became sentient you are unable to       ");
	sayLine("diffeniate the key, among other miscellanous items and zones.  ");
	sayLine("You have a small 3 slot item bag which you can use to help you ");
	sayLine("collect items, throughout your time in the room. However due to");
	sayLine("poor design and budget cuts, you can only move up, down, right,");
	sayLine("left. finally, you have a limited amount of energy, after");
	sayLine("a number of energy you will run out batteries and the game is    ");
	sayLine("over. Also do not touch the fire, you'll get burned! Good Luck!");
	sayLine("------------------------------LEGEND--------------------------- ");
	sayLine("'P' = Player - the user");
	sayLine("'O' = Door/Gate - Exit for the game");
	sayLine("'W' = Fire - Dont touch these");
	sayLine("'?' = Mysterious Items - One of these contain the key");
	sayLine("------------------------MysteriousItems----------------------- ");
	sayLine("One of the following may happen below if you enter a ? Zone");
	std::cout << std::endl;
	sayLine("'K' - Key - Lets you open the door - get revealed once you find it");
	sayLine("Googles - A special Item that helps you reveal the location of the Key");
	sayLine("Battery Charger - A special item that lets you increase you steps ");
	sayLine("Full Charger - A one use item that reset your Energy to Max");
	sayLine("Fire Suit - A suit that gives you immunity to Fire");
	sayLine("*Cursed* - Destroyed - Unfortunate event that random destroy an item slot");
	sayLine("*Cursed* - Heavy Boots - An item that waste more energy with each step");
}

// there is a c++ function but just in case
void sayLine(std::string line) {
	std::cout << line << std::endl;
}

void sayNoEndl(std::string line) {
	std::cout << line;
}

/*************************************************************************
below is a method to check the range of numbers.
*************************************************************************/
void getInt(int &inputIn) {

	int inputInT;

	std::cin >> inputInT;

	while (std::cin.fail() ) {

			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid Input, Please enter a valid integer " << std::endl;
			std::cin >> inputInT;

	}
	//to ensure that no overflow anything carry over.
	std::cin.clear();
	std::cin.ignore(256, '\n');
	inputIn = inputInT;


}
//use utd to check the range
void checkRange(int &inputIn, int cond1, int cond2) {
	int inputInT;

	std::cin >> inputInT;

	while (std::cin.fail() || inputInT < cond1 || inputInT > cond2) {

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid Input, Please enter a integer between " << cond1 << " and " << cond2 << "!" << std::endl;
			std::cin >> inputInT;
		}
		else if (inputInT < cond1) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid Input, Please enter a integer between " << cond1 << " and " << cond2 << "!" << std::endl;
			std::cin >> inputInT;
		}
		else if (inputInT > cond2) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid Input, Please enter a integer between " << cond1 << " and " << cond2 << "!" << std::endl;
			std::cin >> inputInT;
		}

	}
	//to ensure that no overflow anything carry over.
	std::cin.clear();
	std::cin.ignore(256, '\n');
	inputIn = inputInT;
}

//use utd to check the double range
void checkDouble(double &inputIn, double cond1, double cond2) {
	double inputInT;
	std::cin >> inputInT;

	while (std::cin.fail() || inputInT < cond1 || inputInT > cond2) {

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid Input, Please enter a value between " << cond1 << " and " << cond2 << "!" << std::endl;
			std::cin >> inputInT;
		}
		else if (inputInT < cond1) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid Input, Please enter a value between " << cond1 << " and " << cond2 << "!" << std::endl;
			std::cin >> inputInT;
		}
		else if (inputInT > cond2) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid Input, Please enter a value between " << cond1 << " and " << cond2 << "!" << std::endl;
			std::cin >> inputInT;
		}

	}
	//to ensure that no overflow anything carry over.
	std::cin.clear();
	std::cin.ignore(256, '\n');
	inputIn = inputInT;
}


//Get a string 
void checkString(double inputIn) {
	//int numIn;
	std::string input = "";
	while (true) {
		getline(std::cin, input);

		//this code will convert string to numbers
		std::stringstream myStream(input);

		if (myStream >> inputIn) {
			
			break;
		}
		else
			std::cout << "Invalid Number!, Please try again!\n";

	}

	
}