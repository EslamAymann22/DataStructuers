#pragma once
#include<iostream>
using namespace std;

template<class T>
class dequeLinkedList
{
	void add_one(T val);
public:
	class node {
	public:
		node* nxt, * prv;
		T val;
		node(T val = 0, node* nxt = NULL, node* prv = NULL) :
			val(val), nxt(nxt), prv(prv) {}
	};

	int size;
	node* head, * rear;
	dequeLinkedList();
	int GetSize();
	bool empty();
	void push_front(T val);
	void push_back(T val);
	void pop_front();
	void pop_back();
	void display();
	T front();
	T back();
	void clear();
	~dequeLinkedList();

};

template<class T>
inline void dequeLinkedList<T>::add_one(T val)
{
	node* tmp = new node;
	tmp->nxt = rear;
	tmp->prv = head;
	head->nxt = tmp;
	rear->prv = tmp;
	tmp->val = val;
}


template<class T>
dequeLinkedList<T>::dequeLinkedList() {
	size = 0;
	head = new node;
	rear = new node;
	head->nxt = rear;
	rear->prv = head;

}

template<class T>
inline int dequeLinkedList<T>::GetSize()
{
	return size;
}
template<class T>
inline bool dequeLinkedList<T>::empty()
{
	return size == 0;
}

template<class T>
inline void dequeLinkedList<T>::push_front(T val)
{
	if (empty()) {
		add_one(val);
	}
	else {
		node* tmp = new node;
		tmp->val = val;
		tmp->nxt = head->nxt;
		tmp->nxt->prv = tmp;
		tmp->prv = head;
		head->nxt = tmp;
	}
	size++;

}

template<class T>
inline void dequeLinkedList<T>::push_back(T val)
{
	if (empty()) {
		add_one(val);
	}
	else {
		node* tmp = new node;
		tmp->val = val;
		tmp->nxt = rear;
		tmp->prv = rear->prv;
		tmp->prv->nxt = tmp;
		rear->prv = tmp;
	}
	size++;
}

template<class T>
inline void dequeLinkedList<T>::pop_front()
{
	if (empty()) {
		cout << "deque is empty\n";
		return;
	}
	node* tmp = head->nxt;
	head->nxt = tmp->nxt;
	head->nxt->prv = head;
	delete tmp;
	size--;
}

template<class T>
inline void dequeLinkedList<T>::pop_back()
{
	if (empty()) {
		cout << "deque is empty\n";
		return;
	}
	node* tmp = rear->prv;
	rear->prv = tmp->prv;
	rear->prv->nxt = rear;
	delete tmp;
	size--;
}

template<class T>
inline void dequeLinkedList<T>::display()
{
	node* tmp = head->nxt;
	while (tmp != rear) {
		cout << tmp->val;
		tmp = tmp->nxt;
	}
}

template<class T>
inline void dequeLinkedList<T>::clear()
{
	node* tmp = head->nxt;
	node* cur = tmp;
	while (cur != rear) {
		tmp = cur;
		cur = cur->nxt;
		delete tmp;
	}
	head->nxt = rear;
}

template<class T>
dequeLinkedList<T>::~dequeLinkedList()
{
	clear();
	delete head;
	delete rear;
}

template<class T>
inline T dequeLinkedList<T>::front()
{
	if (!size)return -1;
	return head->nxt->val;

}

template<class T>
inline T dequeLinkedList<T>::back()
{
	if (!size)return -1;
	return rear->prv->val;

}
