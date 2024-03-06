#include "stack.h"

bool Stack::is_empty() {
	if (stackvect.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Stack :: insert(int input) {
	stackvect.push_back(input);
}

void Stack::remove() {
	stackvect.pop_back();
}

int Stack :: findTop() {
	return stackvect[(stackvect.size() - 1)];
}

float Stack::average() {
	int total = 0;
	int count = 0;
	for (int i = 0; i <= (stackvect.size()-1); i++) {
		total += stackvect[i];
		count++;
	}
	return (total /count);
}

void Stack::printvect(){
	for (int i = 0; i <= (stackvect.size() - 1); i++) {
		cout << stackvect[i] << " ";
	}
}