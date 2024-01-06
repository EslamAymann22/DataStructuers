#pragma once
#include <bits/stdc++.h>
#include"IDataStructures.h"
using namespace std;
class LinkedList /*:public IDataStructures*/{
public:
	struct node {
		int valu;
		node* nxt;
	};
	int size = 0;
	node* head;
	LinkedList();
	bool empty();
	void push_front(int value);
	void push_back(int value);
	void erase_front();
	void erase_back();
	void insert(int val, int pos = -1);
	void reverse(int start , int end);
	void reverse();
	void display();
	bool seach(int val);
	void erase(int pos = -1);
	int operator [](int idx);
	int get(int idx);
	~LinkedList();
};

