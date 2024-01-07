#pragma once
#include<bits/stdc++.h>
using namespace std;


class MyVector {

	int maxSize;
	int* arr;
	int size;
	bool arrayNotCleared = 1;
public:
	MyVector(int sz, int init);
	int& operator[](int idx);
	bool empty();
	void insert(int val, int pos);
	void erase(int pos);
	void resize();
	void push_back(int val);
	void pop_back();
	int getSize();
	int getCapacity();
	int search(int val);
	void display();
	void clear();
	bool found(int val);
	~MyVector();

};

