#include "stackarray.h"



stackarray::stackarray():arr(new int[1]), maxSize(1), topidx(-1){}


bool stackarray::isFull() {
	return(maxSize >= 1024);// power of 2
}


bool stackarray::resize() {
	if (topidx < maxSize - 1)return 1;
	if (isFull()) {
		cout << "Stack is full\n";
		return 0;
	}
	maxSize++;
	maxSize *= 2;
	int* tmp = new int[maxSize];
	if (arrayNotCleared) {
		for (int i = 0; i <= topidx; i++)
			tmp[i] = arr[i];
		delete[] arr;
	}
	arr = tmp;
	arrayNotCleared = 1;
	return 1;
}

void stackarray::push(int val)
{
	if (resize())
		arr[++topidx] = val;
}

bool stackarray::empty() {
	return (topidx == -1);
}
 
void stackarray::pop() {
	if (empty()) {
		cout << "Underflow!!\n";
	}
	else topidx--;
}

int stackarray::top()
{
	if (empty()) {
		cout << "OVERFLOW!!\n";
		return -1;
	}
	else
		return arr[topidx];
}

int stackarray::size()
{
	return(topidx + 1);
}

stackarray::~stackarray()
{
	if (arrayNotCleared)
		delete[] arr;
	arrayNotCleared = maxSize = 0;
}

void stackarray::clear() {
	if (arrayNotCleared)
		delete[] arr;
	topidx = -1;
	maxSize = 0;
	arrayNotCleared = 0;
}
