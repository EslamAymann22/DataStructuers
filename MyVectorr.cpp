#include "MyVectorr.h"

template<class T>
MyVector<T>::MyVector(int sz, T init) {
	maxSize = max(sz, 0);
	sz = maxSize;
	arr = new T[sz];
	for (int i = 0; i < sz; i++)arr[i] = init;
	size = sz;
	arrayNotCleared = 1;
}
template<class T>
T& MyVector<T>::operator[](int idx) {
	if (idx >= maxSize || idx < 0)
		return cout << "\nERROR!!", arr[0];
	return arr[idx];
}
template<class T>
bool MyVector<T>::empty()
{
	return (size == 0);
}

template<class T>
void MyVector<T>::insert(T val,int pos)
{
	if (size >= maxSize - 1)resize();
	for (int i = size; i > pos; i--)
		arr[i] = arr[i - 1];
	arr[pos] = val;
	size++;
}
template<class T>
void MyVector<T>::erase(int pos)
{
	for (int i = pos; i < size; i++)
		arr[i] = arr[i + 1];
	size--;
}
template<class T>
bool MyVector<T>::isFull() {
	return(maxSize >= 1e6);
}
template<class T>
void MyVector<T>::reverse(int start, int end)
{
	if (end == -1)end = size;
	if (start > end)swap(start, end);
	while (start < end)
		swap(arr[start++], arr[end--]);
}

template<class T>
void MyVector<T>::resize() {
	if (size < maxSize - 1)return;
	if (isFull()) {
		cout << "vector is full\n";
		return;
	}
	maxSize++;
	maxSize *= 2;
	T* tmp = new T[maxSize];
	if (arrayNotCleared) {
		for (int i = 0; i < size; i++)
			tmp[i] = arr[i];
		delete[] arr;
	}
	arr = tmp;
	arrayNotCleared = 1;
}
template<class T>
void MyVector<T>::push_back(T val)
{
	if (size >= maxSize - 1)resize();
	arr[size++] = val;

}

template<class T>
void MyVector<T>::pop_back()
{
	if (empty())return cout << "\nERROR!!", void();
	size--;
}
template<class T>
int MyVector<T>::getSize()
{
	return size;
}

template<class T>
int MyVector<T>::getCapacity()
{
	return maxSize;
}

template<class T>
int MyVector<T>::search(T val)
{
	for (int i = 0; i < size; i++) {
		if (arr[i] == val)return i;
	}
	return -1;
}

template<class T>
void MyVector<T>::display()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
}

template<class T>
void MyVector<T>::clear()
{
	if (arrayNotCleared)
		delete[] arr;
	arrayNotCleared = 0;
	size = maxSize = 0;
}

template<class T>
bool MyVector<T>::found(T val)
{
	return (search(val) != -1);
}

template<class T>
MyVector<T>::~MyVector() {

	maxSize = size = 0;
	if (arrayNotCleared)
		delete[] arr;
}
