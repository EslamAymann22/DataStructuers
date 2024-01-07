#pragma once
#include <iostream>
#include"IDataStructures.h"
using namespace std;

template<class T>
class LinkedList {
public:
	struct node {
		T valu;
		node* nxt;
	};
	int size = 0;
	node* head;
	LinkedList();
	bool empty();
	void push_front(T value);
	void push_back(T value);
	void erase_front();
	void erase_back();
	void insert(T val, int pos = -1);
	void reverse(int start , int end);
	void reverse();
	void display();
	bool search(T val);
	void erase(int pos = -1);
	T& operator [](int idx);
	T get(int idx);
	~LinkedList();
};

