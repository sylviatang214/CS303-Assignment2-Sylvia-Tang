#include "Single_Linked_List.h"

Single_Linked_List::Single_Linked_List() {
	headPtr = nullptr;
	tailPtr = nullptr;
}

void Single_Linked_List::push_front(string input) {
	node* frontNode = new node;
	frontNode->input = input;

	if (headPtr == nullptr) { //if list is empty, set headprt and tailptr as frontNode 
		headPtr = frontNode;
		tailPtr = frontNode;
	}
	else { // add to front
		frontNode->next_node = headPtr;
		headPtr = frontNode;
	}
}

void Single_Linked_List::push_back(string input) {
	node* backNode = new node;
	backNode->input = input;

	if (headPtr == nullptr) { //if list is empty, set headptr and tailptr as backNode 
		headPtr = backNode;
		tailPtr = backNode;
	}
	else { // push to back
		tailPtr->next_node = backNode; 
		tailPtr = backNode; 
	}
}

void  Single_Linked_List::pop_front() {
	if (headPtr == nullptr){
		cout << "\n\nEmpty list"; 
	}
	else {
		node* deleteNode = headPtr;

		if (headPtr == tailPtr) { //if there's one element in the list, set list as empty
			headPtr = nullptr; 
			tailPtr = nullptr;
		} 
		else { //point head pointer to the next available node in the list
			headPtr = headPtr->next_node; 
		}

		delete deleteNode;
	}
}

void  Single_Linked_List::pop_back() {
	if (headPtr == nullptr) {
		cout << "\n\nEmpty list";
	}
	else {

		node* deleteNode = tailPtr; // set the node to delete to be the final node

		if (headPtr == tailPtr) { //if there's one element in the list, set list as empty
			headPtr = nullptr;
			tailPtr = nullptr;
		}
		else {
			node* tempNode = headPtr;

			while (tempNode->next_node!= tailPtr) { //while next node is not tail pointer
				tempNode = tempNode->next_node; //move tempnode to next node in the list until tempnode is second to last node in the list
			} 
			tailPtr = tempNode; //set second to last node in the list as new tail pointer
			tailPtr->next_node = nullptr; //new tail pointer points to null

		}

		delete deleteNode;
	}
}

void Single_Linked_List::front() { // print first index data in the list
	cout << "\n\nfront input: " << headPtr->input; 
}

void Single_Linked_List::back() { //print last index data in the list
	cout << "\n\nback input: " << tailPtr->input; 
}

bool Single_Linked_List::empty() { //check if the list is empty
	if (headPtr == nullptr) {
		return true;
	}
	else {
		return false;
	}
}



// Insert item at position index (starting at 0).Insert at the end if index is beyond the end of the list
void Single_Linked_List::insert(int index, string input) {
	if (empty()) {
		push_front(input);
	}
	else if (index == 0) {
		push_front(input);
	}
	else {
		node* insertNode = new node;
		insertNode->input = input;
		node* tempNode = headPtr;

		for (int i = 1; i < index; i++) {
			if (tempNode == nullptr) {
				push_back(input);
				return;
			}
			else {
				tempNode = tempNode->next_node;
			}

		}
		insertNode->next_node = tempNode->next_node;
		tempNode->next_node = insertNode;

	}
}

// Remove the item at position index.Return true if successful; return false if index is beyond the end of the list.
bool Single_Linked_List::remove(int index) {
	if (empty()) {
		return false;
	}
	else if (index == 0) {
		pop_front();
	}
	else {
		node* tempNode = headPtr;

		for (int i = 1; i < index; i++) {
			if (tempNode == nullptr) {
				return false;
			}
			else {
				tempNode = tempNode->next_node;
			}

		}
		node* removeNode = tempNode->next_node;
		tempNode->next_node = removeNode->next_node;

		delete removeNode;
		return true;

	}
}


//Return the position of the first occurrence of item if it is found.Return the size of the list if it is not found.
int Single_Linked_List::find(string input) {
	if (empty()) {
		cout << "\n\nEmpty list";
	}
	else {
		node* tempNode = headPtr;
		int position = 0;

		while(tempNode != nullptr) { //while tempNode is not null
			if (tempNode->input == input) { //if item is found, return index position
				return position;
			}
			else {
				position++; //increment index position
			}
			tempNode = tempNode->next_node;
		}
		return (position + 1); //returns size of list
	}
}

void Single_Linked_List::print() {

	if (empty()) {
		cout << "\n\nEmpty list";
	}
	else {
		node* tempNode = headPtr;
		cout << "Current list: ";
		while (tempNode != nullptr) { //while tempNode is not null, print
			cout << tempNode->input << " ";
			tempNode = tempNode->next_node;
		}
	}

	cout << "\n\n";
}