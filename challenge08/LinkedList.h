#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.h"     // contains the node information
#include <iostream>   // for using cout

using namespace std;

template<typename T>    // templated class
class LinkedList {	

		friend LinkedList<T>* operator+<>(const LinkedList<T> &A, const LinkedList<T> &B); //instantiate operator

	public:
		LinkedList();    // constructor
		~LinkedList();   // deconstructor

		bool empty();   // if the list is empty
		void print();   // display contents of the list
		int  nodeCount();  // how many nodes are in the list
		void pushBack(const T &data);  //adds nodes to back of list
		void pushFront(const T &data);  //adds nodes to front of list
	private:
		Node<T> *head; // head element in the list
		Node<T> *tail;  //last element in list
		Node<T> *newNode(const T &); // helper function; creates a new node
};

// constructor (empty body)
template<typename T>
LinkedList<T>::LinkedList() :head(NULL), tail(NULL) {}

// destructor
template<typename T>
LinkedList<T>::~LinkedList() {
	//implement this
}

// predicate: is this list empty?
template<typename T>
bool LinkedList<T>::empty() { 
	//implement this
	return false;
}

// utility function to create a node
template<typename T>
Node<T> *LinkedList<T>::newNode(const T &value) {
	//implement this
	return NULL;
}

//prints out list elements in correct order
template<typename T>
void LinkedList<T>::print() {
	//implement this
}

//count nodes
template<typename T>
int LinkedList<T>::nodeCount(void) {
	//implement this
	return 0;
}

//add new nodes (and data) to end of list
template<typename T>
void LinkedList<T>::pushBack(const T &data){
	//implement this
}

//add new nodes (and data) to front of list
template<typename T>
void LinkedList<T>::pushFront(const T &data){
	//implement this
}

//overload + to use with templated class
template<typename T>
LinkedList<T>* operator+(const LinkedList<T> &A, const LinkedList<T> &B){
	//implement this
	LinkedList<T> *returnList = new LinkedList<T>;
	return returnList;
}

#endif
