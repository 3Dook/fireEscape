/***********************************************************************************
Name:
Author: Duc Doan
Date: 3/3/2019
Description:
************************************************************************************/


#ifndef DLINK_HPP
#define DLINK_HPP

#include <iostream>
#include "item.hpp"
#include <string>

struct Node {
	Item *val;
	struct Node *next;
	struct Node *prev;
};

class List {

private:
	Node *head;
	Node *tail;
	std::string teamName;

public:
	//constructor
	List();
	List(std::string nameIn);
	//methods
	//void makeNode(Item *valIn);
	void insertHead(Item *valIn);
	void insertTail(Item *valIn);

	//delete
	void deleteHead();
	void deleteTail();

	//read
	void read();
	void readReverse();

	//EC
	//Print head
	void getHead();
	void getTail();

	//additonal methods; for program
	std::string getLinkName();

	Item *getItem();
};
#endif // !LINK_HPP
