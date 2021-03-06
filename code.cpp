// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;


struct node {
	int data;
	node *next;
};


class list {
private:
	node *head, *tail;
public:
	list() {
		head = NULL;
		tail = NULL;
	}

	void createnode(int value) {
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;

		// check if this is the first node in the list
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
			// temp = NULL ??
		}
	}

	void display() {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void insert_start(int value) {
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}

	void insert_end(int value) {
		node *temp = new node;
		temp->data = value;
		tail->next = temp;
		tail = temp;
	}

	void insert_at_pos(int value, int pos) {
		node *pre = new node;
		node *cur = new node;

		node *temp = new node;
		temp->data = value;

		cur = head;

		for (int i = 1; i <= pos; i++) {
			pre = cur;
			cur = cur->next;
		}

		pre->next = temp;
		temp->next = cur;
	}

	void delete_start() {
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}

	void delete_end() {
		node *cur = new node;
		node *pre = new node;
		cur = head;
		while (cur->next != NULL) {
			pre = cur;
			cur = cur->next;
		}
		tail = pre;
		pre->next = NULL;
		delete cur;
	}

	// wrong
	void delete_at_pos(int pos) {
		node *cur = new node;
		node *pre = new node;
		node *temp = new node;
		cur = head;
		for (int i = 1; i <= pos; i++) {
			pre = cur;
			cur = cur->next;
		}
		temp = cur;
		pre->next = cur;
		delete temp;
	}

	void create_node_17() {
		node *current = new node;
		node *node_17 = new node;

		current = head;
		while (current->data != 65) {
			current = current->next;
		}

		node_17->next = current->next;
		current->next = node_17;
	}

	void delete_last_node() {
		node *current = new node;
		node *previous = new node;

		current = head;

		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}

		tail = previous;
		tail->next = NULL;
		delete current;

	}

	void delete_node_92() {
		node *current = new node;
		node *previous = new node;

		current = head;
		
		while (current->data != 92) {
			previous = current;
			current = current->next;
		}

		previous->next = current->next;
		current->next = NULL;
		delete current;
	}

	void move_node_46() {
		node *node_65 = new node;
		node *node_80 = new node;
		node *node_46 = new node;

		node_65 = head;

		while (node_65->data != 65) {
			node_65 = node_65->next;
		}

		node_80 = node_65->next;
		node_46 = node_80->next;

		node_65->next = node_46;
		node_80->next = node_46->next;
		node_46->next = node_80;
	}



};


int second(stack<int> myStack) {
	for (int i = myStack.size(); i > 2; i--) {
		myStack.pop();
	}
	int second = myStack.top();
	return second;
}


int main()
{
	// **************************
	// Linked Lists
	// **************************

	list linked_list;

	// creating nodes
	linked_list.createnode(47);
	linked_list.createnode(12);
	linked_list.createnode(92);
	linked_list.createnode(65);
	linked_list.createnode(80);
	linked_list.createnode(46);
	linked_list.createnode(5);
	linked_list.createnode(78);

	// insert info 17
	// linked_list.insert_at_pos(17, 4);

	// delete at end
	//linked_list.delete_end();

	// delete at pos 3
	// linked_list.delete_at_pos(3);

	// delete last node
	//linked_list.delete_last_node();

	// delete node 92
	//linked_list.delete_node_92();

	// move node 46 next to current
	//linked_list.move_node_46();

	// Display list
	//linked_list.display();

	// **************************
	// Stacks
	// **************************

	stack<int> myStack;
	
	for (int i = 1; i <= 5; i++) {
		myStack.push(i);
	}

	cout << "Second element of the stack is: " << second(myStack) << endl;
	return 0;
}