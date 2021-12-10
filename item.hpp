/***********************************************************************************
Name: item.hpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a header file. It contains will define a item class
that will be use in other parts of the program an game. 
************************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item {

private:
	std::string name;
	std::string description;
public:
	//constructor
	Item();
	Item(std::string s1, std::string s2);
	~Item();

	void setName(std::string s1);
	void setDescription(std::string s2);

	std::string getName();
	std::string getDescription();
	std::string getType();
};


#endif // !ITEM_HPP
