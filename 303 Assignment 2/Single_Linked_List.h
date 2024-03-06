#pragma once

#include <string>
#include<iostream>
using namespace std;

class node {
public:
	node* next_node = nullptr;
	string input = "0";
};

class Single_Linked_List {
private:
	node* headPtr;
	node* tailPtr;
public:
	Single_Linked_List();

	void push_front(string input);
	void push_back(string input);
	void pop_front();
	void pop_back();
	void front();
	void back();
	bool empty();

	void insert(int index, string input);
	bool remove(int index);
	int find(string input);

	void print();

};
