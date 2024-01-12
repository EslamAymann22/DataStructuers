#pragma once
#include <iostream>
//#include <xkeycheck.h>
using namespace std;

template<class T>
class queueLinkedList {

	class node {
	public:
		T val;
		node* nxt;
		node(T val=-1,node* nxt=NULL):val(val),nxt(nxt){}
	};
public:
	node* head, * rear;
	int size;
	queueLinkedList();
	void push(T val);
	void pop();
	bool empty();
	int GetSize();
	void clear();
	~queueLinkedList();


};

template<class T>
inline queueLinkedList<T>::queueLinkedList()
{
	size = 0;
	head = new node;
	rear = head;

}

template<class T>
inline void queueLinkedList<T>::push(T val)
{
	node* add = new node;
	add->val = val;
	rear->nxt = add; 
	rear = add;
	size++;
}

template<class T>
inline void queueLinkedList<T>::pop()
{
	if (size == 0)return cout << "queue is empty\n", void();
	node* cur = head->nxt->nxt;
	delete head->nxt;
	head->nxt = cur;
	size--;
	if (!size)rear = head;
}

template<class T>
inline bool queueLinkedList<T>::empty()
{
	return head == rear;
}

template<class T>
inline int queueLinkedList<T>::GetSize()
{
	return size;
}

template<class T>
inline void queueLinkedList<T>::clear()
{
	while (size--)pop();
}

template<class T>
inline queueLinkedList<T>::~queueLinkedList()
{
	clear();
	delete head;
	delete rear;
}
