#ifndef _NODE_H_
#define _NODE_H_
#include<iostream>

template<typename T> class LinkedList; // forward declaration of List

template<typename T> //forward declaration of assignment operator 
LinkedList<T>* operator+(const LinkedList<T> &A, const LinkedList<T> &B);

template<typename T>   // templated node type
class Node {

	friend class LinkedList<T>;    // make the main class a friend
	friend LinkedList<T>* operator+<>(const LinkedList<T> &A, const LinkedList<T> &B);	  //make the operator + a friend

	public:
	Node(const T &);     // constructor
	T getData() const;   // get function

	private:
	T data;           // data for linked list node
	Node<T> *next;    // pointer to next object
	Node<T> *prev;	  // pointer to prev oject
};

// NOTE:  all of the functions are in the .h file to overcome issues with
//templates and linking

// constructor, using member initialization list syntax
template<typename T>
Node<T>::Node(const T &info) :data(info),next(NULL),prev(NULL) {}

// simple get function for our class (if friendship is not used)
template<typename T>
T Node<T>::getData(void) const { return data; }

#endif
