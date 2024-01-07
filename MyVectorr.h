#pragma once
#include<iostream>
using namespace std;

template <class T>
class MyVector {

	int maxSize;
	T* arr;
	int size;
	bool arrayNotCleared = 1;
public:
	MyVector(int sz, T init = 0);
	T& operator[](int idx);
	bool empty();
	void insert(T val, int pos);
	void erase(int pos);
	void resize();
	void push_back(T val);
	void pop_back();
	int getSize();
	int getCapacity();
	int search(T val);
	void display();
	void clear();
	bool found(T val);
	bool isFull();
	void reverse(int start = 0, int end = -1);
	~MyVector();

};

