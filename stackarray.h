#pragma once
#include<iostream>
using namespace std;

template <class T>
class stack
{
	T* arr;
	int maxSize;
	int topidx;
	bool arrayNotCleared = 1;
public:
	stack();
	bool isFull();
	bool empty();
	bool resize();
	void clear();
	void push(T val);
	void pop();
	T top();
	int size();
	~stack();
};

