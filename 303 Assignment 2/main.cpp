#include "stack.h"
#include "Single_Linked_List.h"

int main(){
	//********
	//***Q1***
	//********

	Single_Linked_List list;
	string command = "0";
	int index = 0;

	//push back functions
	list.push_back("0");
	list.push_back("1");
	list.push_back("2");
	list.push_back("3");
	list.push_back("4");
	list.push_back("5");
	//push front functions
	list.push_front("f");
	list.push_front("e");
	list.push_front("d");
	list.push_front("c");
	list.push_front("b");
	list.push_front("a");

	//update list
	list.print();

	//pop front function
	do {
		cout << "\n\nPop front? (y/n) ";
		cin >> command;
		if (command == "y") {
			list.pop_front();
			list.print();
		}
		else {
			command = "n";
		}
	} while (command == "y");

	//pop back function
	do {
		cout << "\n\nPop back? (y/n) ";
		cin >> command;
		if (command == "y") {
			list.pop_back();
			list.print();
		}
		else {
			command = "n";
		}
	} while (command == "y");


	//update list
	list.print();

	//front and back item
	list.front();
	list.back();

	cout << "\n\nRemove index? (y/n) ";
	cin >> command;
	if (command == "y") {
		cout << "Enter index to remove: ";
		cin >> index;
		list.remove(index);
		command = "0";
	}
	
	//update list
	list.print();


	if (list.empty()) {
		cout << "The list is empty." << endl;
	}
	else {
		cout << "The list is not empty." << endl;
	}

	string item = "\0";
	//insert function
	do {
		cout << "\n\nInsert item? (y/n) ";
		cin >> command;
		if (command == "y") {
			cout << "\nEnter index & item to insert: ";
			cin >> index;
			cin >> item;
			list.insert(index, item);
			list.print();
		}
	} while (command == "y");


	do {
		cout << "\n\nRemove item? (y/n) ";
		cin >> command;
		if (command == "y") {
			cout << "\nEnter index to remove item: ";
			cin >> index;
			list.remove(index);
			list.print();
		}
	} while (command == "y");

	cout << "\n\nEnter item to search in the list: ";
	cin >> item;
	cout << "Item position: " << list.find(item) << endl;


	//********
	//***Q2***
	//********


	//Q2 1 Create a stack object
	Stack stack1;

	//Q2 2 Check the stack is empty or not
	if (stack1.is_empty() == 1) {
		cout << "stack is empty" << endl;
	}
	else {
		cout << "stack is not empty" << endl;
	}

	//Q2 3 Insert some integer values onto the stack
	char command = 'y';

	while (command == 'y') {
		cout << "\nenter number to insert: " << endl;
		int input;
		cin >> input;
		stack1.insert(input);
		cout << "insert another? enter (y/n)" << endl;
		cin >> command;
	}

	cout << "\stack update: ";
	stack1.printvect();

	//Q2 4 Remove an element from the stack
	char command1 = 'y';

	while (command1 == 'y') {
		cout << "\nremove from the stack?(y/n)" << endl;
		cin >> command1;
		if (command1 == 'y') {
			stack1.remove();
		}
		else {
			break;
		}
	}
	cout << "\stack update: ";
	stack1.printvect();

	//Q2 5 Find the Top of the stack
	cout << "\n\nTop of the stack: " << stack1.findTop() << endl;

	//Q2 6 Find average value of the stack elements.
	cout << "Average value: " << stack1.average() << endl;

	system("pause");
	return 0;
}