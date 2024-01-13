#pragma once
#include<iostream>
using namespace std;

template <class T>
class stackLinkedList
{
	class node {
	public:
		T val;
		node* nxt;
		node(T val=-1, node* nxt=NULL) :val(val), nxt(nxt) {}
	};
	node* start;
	int size;
public:
	stackLinkedList();
	void push(T val);
	bool empty();
	int Getsize();
	void pop();
	T top();
	void clear();
	~stackLinkedList();
};

template<class T>
inline stackLinkedList<T>::stackLinkedList()
{
	start = (new node);
	size = 0;
}

template<class T>
inline void stackLinkedList<T>::push(T val) {
	node* tmp = new node(val);
	tmp->nxt = start->nxt;
	start->nxt = tmp;
	size++;
}
template<class T>
inline bool stackLinkedList<T>::empty() {
	return (size == 0);
}

template<class T>
inline int stackLinkedList<T>::Getsize() {
	return size;
}

template<class T>
inline void stackLinkedList<T>::pop() {

	if (size == 0)cout << "Stack is enpty\n";
	else {
		node* cur = start->nxt;
		start->nxt = cur->nxt;
		delete cur;
		size--;
	}
}

template<class T>
inline T stackLinkedList<T>::top() {
	if (size == 0)return cout << "Stack is enpty\n", -1;
	return start->nxt->val;
}

template<class T>
inline void stackLinkedList<T>::clear()
{
	while (start->nxt != NULL) {
		pop();
	}
}

template<class T>
inline stackLinkedList<T>::~stackLinkedList()
{
	clear();
	delete start;
}
