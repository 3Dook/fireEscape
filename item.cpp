/***********************************************************************************
Name: item.cpp
Author: Duc Doan
Date: 3/19/2019
Description: This is a cpp file. It will further define the methods for our HPP files.
************************************************************************************/
#include "item.hpp"

/*
class Item {

private:
	std::string name;
	std::string description;
public:
	//constructor
	Item();
	item(std::string s1, std::string s2);
	~Item();

	std::string getName();
	std::string getDescription();

};
*/

Item::Item(){
	name = "";
	description = "";
}

Item::Item(std::string s1, std::string s2){
	name = s1;
	description = s2;
}

Item::~Item(){
}

std::string Item::getName(){
	return name;
}

std::string Item::getDescription() {
	return description;
}
void Item::setName(std::string s1) {
	name = s1;
}

void Item::setDescription(std::string s2) {
	description = s2;
}

std::string Item::getType() {
	return name + " - " + description;

}