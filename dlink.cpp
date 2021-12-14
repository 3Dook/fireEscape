/***********************************************************************************
Name:
Author: Duc Doan
Date: 2/17/2019
Description:
************************************************************************************/


#include "dlink.hpp"


List::List() {
	head = nullptr;
	tail = nullptr;
	teamName = "Super Secret";
}

List::List(std::string nameIn) {

	head = nullptr;
	tail = nullptr;
	teamName = nameIn;

}
//methods
/* glitchy
void List::makeNode(Item *valIn) {
	//create of a new node
	Node *temp = new Node;
	temp->val = valIn;
	temp->next = nullptr;

	if (head == nullptr) {
		head = temp;
		tail = temp;
		temp = nullptr;
	}
	else {
		tail->next = temp;
		tail = temp;
		temp = nullptr;
	}
}
*/
//
std::string List::getLinkName() {
	return teamName;
}

void List::insertHead(Item *valIn) {
	Node *temp = new Node;

	//temp->next = nullptr;
	temp->val = valIn;
	temp->prev = nullptr;
	temp->next = nullptr;


	if (head == nullptr) {
		head = tail = temp;
	}
	else {
		head->prev = temp;
		temp->next = head;
		head = temp;
	}


	//this->read();
}
void List::insertTail(Item *valIn) {
	Node *temp = new Node;
	temp->val = valIn;

	temp->next = nullptr;
	temp->val = valIn;
	temp->prev = nullptr;

	if (tail == nullptr) {
		head = tail = temp;
	}
	else {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}

	//this->read();
}

//delete
void List::deleteHead() {
	if (head == nullptr) {
		std::cout << "No Head to delete..Returning to main menu" << std::endl;
		return;
	}
	Node *temp = new Node;
	temp->prev = nullptr;
	temp->next = nullptr;


	if (head->next == nullptr) {
		//std::cout << "I should have delete the last one - HEAD\n";
		temp = head;
		head = nullptr;
		tail = nullptr;
		delete temp;
	}
	else {
		temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}

	// read off list
	//this->read();
}
void List::deleteTail() {
	if (tail == nullptr) {
		std::cout << "No Tail to delete..Returning to main menu" << std::endl;
		return;
	}

	Node *temp = new Node;
	temp->prev = nullptr;
	temp->next = nullptr;


	delete temp;
	if (tail->prev == nullptr) {
		temp = tail;
		tail = nullptr;
		head = nullptr;
		free(temp);
	}
	else {
		temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		free(temp);
	}

	//read off list
	//this->read();
}

//read
void List::read() {

	Node *temp = new Node;

	temp = head;
	if (temp == nullptr) {
		std::cout << "Empty List..." << std::endl;
		return;
	}
	if (tail == nullptr) {
		std::cout << "Empty List..." << std::endl;
		return;
	}
	while (temp != nullptr) {
		// points to the node and read out the type ;'(, 
		std::cout << temp->val->getType();
		std::cout << "\n";
		temp = temp->next;
	}
	//std::cout << std::endl;

}
void List::readReverse() {
	Node *temp = new Node;
	temp = tail;
	//If list is empty exit
	if (temp == nullptr) {
		std::cout << "No list created, returning to main menu" << std::endl;
		return;
	}
	if (head == nullptr) {
		std::cout << "No list created, returning to main menu" << std::endl;
		return;
	}
	while (temp != nullptr) {
		std::cout << temp->val->getType();
		std::cout << "\n";
		temp = temp->prev;
	}
	std::cout << std::endl;
}

void List::getHead() {
	if (head == nullptr) {
		std::cout << "No Head exist..Returning to main menu" << std::endl;
		return;
	}
	std::cout << head->val << std::endl;
}

void List::getTail() {
	if (tail == nullptr) {
		std::cout << "No Tail exist..Returning to main menu" << std::endl;
		return;
	}
	std::cout << tail->val << std::endl;
}

Item *List::getItem() {
	if (head == nullptr) {
		//std::cout << "No Head Fighter exist.." << std::endl;
		return NULL;
	}
	else {
		return head->val;
	}

}