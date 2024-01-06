#pragma once
#include <bits/stdc++.h>
using namespace std;
class LinkedList {
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
	void reverse(int start = 0, int end = -1);
	void display();
	void erase(int pos = -1);
	int operator [](int idx);
	int get(int idx);
	~LinkedList();
};

