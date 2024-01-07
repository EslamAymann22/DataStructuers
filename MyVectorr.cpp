#include "MyVectorr.h"
MyVector::MyVector(int sz, int init) {
	maxSize = max(sz, 1);
	sz = maxSize;
	arr = new int[sz];
	for (int i = 0; i < sz; i++)arr[i] = init;
	size = sz;
	arrayNotCleared = 1;
}
 
int& MyVector::operator[](int idx) {
	if (idx >= maxSize || idx < 0)
		return cout << "\nERROR!!", arr[0];
	return arr[idx];
}

bool MyVector::empty()
{
	return (size == 0);
}


void MyVector::insert(int val,int pos)
{
	if (size >= maxSize - 1)resize();
	for (int i = size; i > pos; i--)
		arr[i] = arr[i - 1];
	arr[pos] = val;
	size++;
}

void MyVector::erase(int pos)
{
	for (int i = pos; i < size; i++)
		arr[i] = arr[i + 1];
	size--;
}

void MyVector::resize() {
	if (size < maxSize - 1)return;
	maxSize++;
	maxSize *= 2;
	int* tmp = new int[maxSize];
	if (arrayNotCleared) {
		for (int i = 0; i < maxSize; i++)
			tmp[i] = arr[i];
		delete[] arr;
	}
	arr = tmp;
	arrayNotCleared = 1;

}
void MyVector::push_back(int val)
{
	if (size >= maxSize - 1)resize();
	arr[size++] = val;

}

void MyVector::pop_back()
{
	if (size == 0)return cout << "\nERROR!!", void();
	size--;
}

int MyVector::getSize()
{
	return size;
}

int MyVector::getCapacity()
{
	return maxSize;
}

int MyVector::search(int val)
{
	for (int i = 0; i < size; i++) {
		if (arr[i] == val)return i;
	}
	return -1;
}

void MyVector::display()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
}

void MyVector::clear()
{
	arrayNotCleared = 0;
	size = maxSize = 0;
	delete[] arr;
}

bool MyVector::found(int val)
{
	return (search(val) != -1);
}

MyVector::~MyVector() {

	maxSize = size = 0;
	if (arrayNotCleared)
		delete[] arr;
}