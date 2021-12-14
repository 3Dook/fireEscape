/***********************************************************************************
Name: menu.hpp
Author: Duc Doan
Date: 2/17/2019
Description: This is a menu helper file. it contain useful prompts and functions to
add in developing and organizing our programs. 

************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include<iostream>
#include<string>
#include<sstream>
//random functions
#include <ctime>
#include <cstdlib>
//vector
#include <vector>
class Menu {

private:


public:
	Menu() {}
	~Menu() {}
	
	//Big program to run everything.
	void runProgram();

	// functions
	void prompt(int choiceIn);
	void display(); 
	void rules();
};


// helper functions for validation

// get an integer within range
//use utd to check the range
void getInt(int &inputIn);
void checkRange(int &inputIn, int cond1, int cond2);
//get a double within Range
void checkDouble(double &inputIn, double cond1, double cond2);
//Get a string 
/*Use getLine(cin, string input) to get a valid Sentence*/
void checkString(double inputIn);
// get a single Char

// there is a c++ function but just in case
void sayLine(std::string line);
void sayNoEndl(std::string line);
#endif // !"MENU_HPP"
