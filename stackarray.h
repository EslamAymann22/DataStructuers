#pragma once
#include<iostream>
using namespace std;

class stackarray
{
	int* arr;
	int maxSize;
	int topidx;
	bool arrayNotCleared = 1;
public:
	stackarray();
	bool isFull();
	bool empty();
	bool resize();
	void clear();
	void push(int val);
	void pop();
	int top();
	int size();
	~stackarray();
};

