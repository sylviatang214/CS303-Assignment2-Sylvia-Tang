#pragma once
using namespace std;
#include <vector>
#include <string>
#include <iostream>

struct Stack {
	
public:
	vector<int> stackvect;

	bool is_empty();
	void insert(int input);
	void remove();
	int findTop();
	float average();
	void printvect();

};