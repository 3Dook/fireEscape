/***********************************************************************************
Name:main.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a main file, to implement our game
************************************************************************************/



#include "menu.hpp"
#include "grid.hpp"

int main() {
	// initialize random seed
	srand(time(NULL));

	Menu menu;
	//menu.runProgram();
	int prompt = 1;
	//List lst;
	int choice;
	Grid gameBoard;
	
	//system("pause");

	std::cout << "Welcome to Final Project - Escape the Lab" << std::endl;
	sayLine("Project and design by Duc Doan");

	while (prompt > 0) {
		Grid temp;
		gameBoard = temp;
		gameBoard.setGrid(); // set up gameBoard
		menu.display();
		checkRange(choice, 1, 4);
		switch (choice) {
		case 1:
			// Rules
			menu.rules();
			break;
		case 2:
			// GamePlay
			gameBoard.runGame();
			// reset the game for the future
			break;
		case 3:
			//Exit
			prompt = 0;
			break;

		}


	}

	//system("pause");
	return 0;
}