#include <iostream>
#include <assert.h> 

class DLL {

private:
	//struct that defines our nodes.
	struct Node {
		int data;
		struct Node *prev;
		struct Node *next;
	};

	//define the head.
	Node* head;
	int Count;

public:
	//basic constructor for the doubley linked list
	DLL() {
		head = NULL;
		Count = 0;
	}

	void insert(int newdata) {

		// allocate node 
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

		// put in the data 
		new_node->data = newdata;

		// link the old list  
		// off the new node  
		new_node->next = head;

		// move the head to point 
		// to the new node  
		head = new_node;
		Count++;
	}

	void display() {
		struct Node* ptr;
		ptr = head;
		while (ptr != NULL) {
			std::cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}

	void setEntry(int loc, int newValue) {

		struct Node* current = head;

		// the index of the  
		// node we're currently 
		// looking at 
		int count = 0;
		while (current != NULL)
		{
			if (count == loc) {
				current->data = newValue;
			}
			count++;
			current = current->next;
		}
	}

	int retrieve(int loc) {

		struct Node* current = head;

		// the index of the  
		// node we're currently 
		// looking at 
		int count = 0;
		while (current != NULL)
		{
			if (count == loc)
				return(current->data);
			count++;
			current = current->next;
		}

	}

	int getLength() {
		return Count;
	}
};