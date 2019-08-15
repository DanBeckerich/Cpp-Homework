#include "node.cpp"
#include <iostream>
#include <string>
#include <sstream>

//source https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr

using namespace std;

class SLL
{
private:
	//convert chars 0-9 to an integer
	int char_to_int(char character) {
		stringstream temp;
		temp << character;
		int x;
		temp >> x;
		return x;
	}

public:
	node *head;
	node *tail;
	int size;


	SLL()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void insert_start(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
		size++;
	}

	void printReverse(struct node* head)
	{
		// Base case   
		if (head == NULL)
			return;

		// print the list after head node 
		printReverse(head->next);

		// After everything else is printed, print head 
		cout << head->data;
	}

	void print(struct node* head)
	{
		// Base case   
		if (head == NULL)
			return;

		//same as before, just reversed.
		cout << head->data;
		print(head->next);

	}

	//loop over every digit adding it to the SLL
	void parseInt(int num) {
		string temp = to_string(num);

		for (int i = 0; i < temp.size(); i++) {
			this->insert_start(this->char_to_int(temp[i]));
		}
	}
};