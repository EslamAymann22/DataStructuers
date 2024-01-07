#include "stackarray.h"


//stack::stack():arr(new T[1]),maxSize(1),topidx(-1){}

template<class T>
stack<T>::stack():arr(new T[1]), maxSize(1), topidx(-1){}

template<class T>
bool stack<T>::isFull() {
	return(maxSize >= 1024);// power of 2
}

template<class T>
bool stack<T>::resize() {
	if (topidx < maxSize - 1)return 1;
	if (isFull()) {
		cout << "Stack is full\n";
		return 0;
	}
	maxSize++;
	maxSize *= 2;
	T* tmp = new T[maxSize];
	if (arrayNotCleared) {
		for (int i = 0; i <= topidx; i++)
			tmp[i] = arr[i];
		delete[] arr;
	}
	arr = tmp;
	arrayNotCleared = 1;
	return 1;
}
template<class T>
void stack<T>::push(T val)
{
	if (resize())
		arr[++topidx] = val;
}
template<class T>
bool stack<T>::empty() {
	return (topidx == -1);
}
template<class T>
void stack<T>::pop() {
	if (empty()) {
		cout << "Underflow!!\n";
	}
	else topidx--;
}
template<class T>
T stack<T>::top()
{
	if (empty()) {
		cout << "OVERFLOW!!\n";
		return -1;
	}
	else
		return arr[topidx];
}
template<class T>
int stack<T>::size()
{
	return(topidx + 1);
}
template<class T>
stack<T>::~stack()
{
	if (arrayNotCleared)
		delete[] arr;
	arrayNotCleared = maxSize = 0;
}
template<class T>
void stack<T>::clear() {
	if (arrayNotCleared)
		delete[] arr;
	topidx = -1;
	maxSize = 0;
	arrayNotCleared = 0;
}
