#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() {
	head = new node;
	head->nxt = NULL;
	size = 0;
	// head == first element
}
template<class T>
bool LinkedList<T>::empty()
{
	return (size == 0);
}

template<class T>
void LinkedList<T>::push_front(T value)
{
	if (size == 0) {//fist element == head
		head->valu = value;
	}
	else {
		node* tmp = new node;
		tmp->nxt = head;
		tmp->valu = value;
		head = tmp;
	}
	size++;//increase size 
}

template<class T>
void LinkedList<T>::push_back(T value)
{
	node* tmp = head;

	while (tmp->nxt != NULL) {
		tmp = tmp->nxt;
	}
	if (size == 0) {// head == first element
		head->valu = value;
	}
	else {
		node* neww = new node;
		neww->valu = value;
		neww->nxt = NULL;
		tmp->nxt = neww;
	}
	size++;//increase size 
}

template<class T>
void LinkedList<T>::erase_front()
{
	if (size == 0) {
		cout << "\nERROR!!"; 
		return;
	}
	else if (size == 1) {
		//head->valu = nothing
	}
	else {
		node* tmp = head;
		head = head->nxt;
		delete tmp;
	}
	size--;//decrease size
}

template<class T>
void LinkedList<T>::erase_back()
{
	if (size == 0) {
		cout << "\nERROR!!"; 
		return;
	}
	else if (size == 1) {
		//head->valu = nothing
	}
	else {
		node* tmp = head;
		while (tmp->nxt->nxt != NULL) {
			tmp = tmp->nxt;
		}
		delete tmp->nxt;
		tmp->nxt = NULL;
	}
	size--;//decrease size
}

template<class T>
void LinkedList<T>::insert(T val, int pos)
{
	if (pos == -1 || pos == size) {
		push_back(val);
	}
	else if (pos >= size) {
		cout << "\nERROR!!";
	}
	else if (pos == 0) {
		push_front(val);
	}
	else {
		node* tmp = head;
		while (--pos) {
			tmp = tmp->nxt;
		}
		node* neww = new node;
		neww->valu = val;
		neww->nxt = tmp->nxt;
		tmp->nxt = neww;
		size++;			//increase size
	}
}

template<class T>
void LinkedList<T>::reverse(int start, int end)
{
	if (start > end)swap(start, end);
	if (start == end)return;
	if (start == 0 and end == size - 1) {
		reverse();
		return;
	}
	bool StartIsAHead = (start == 0);
	node* last = NULL;
	node* cur = head;
	node* next = head->nxt;

	node* savestart;
	node* savelast;
	savelast = savestart = head;
	while (start--) {
		last = cur;
		cur = cur->nxt;
		end--;
	}
	savestart = cur;/////////////////////////
	savelast = last;////////////////////////
	next = cur->nxt;
	end++;
	while (end--) {
		cur->nxt = last;
		if (!end)break;
		last = cur;
		cur = next;
		next = next->nxt;
	}
	//cur->nxt=
	if (savelast != NULL)
		savelast->nxt = cur;
	if (savestart != NULL)
		savestart->nxt = next;
	if (StartIsAHead)head = cur;
}

template<class T>
void LinkedList<T>::reverse()
{

	if (size < 2)return;
	node* last = NULL;
	node* cur = head;
	node* next =  head->nxt;
	while (next != NULL) {
		cur->nxt = last;
		last = cur;
		cur = next;
		next = next->nxt;
	}
	head = cur;
	head->nxt = last;
}

template<class T>
void LinkedList<T>::display()
{
	node* tmp = head;
	int sz = size;
	// while (tmp!=NULL) ==> make a problem because if size == 0 and head still have value
	while (sz--) {
		cout << tmp->valu << ' ';
		tmp = tmp->nxt;
	}
}

template<class T>
bool LinkedList<T>::search(T val)
{
	node* cur = head;
	while (cur != NULL) {
		if (cur->valu == val)return true;
		cur = cur->nxt;
	}
	return false;
}

template<class T>
void LinkedList<T>::erase(int pos)
{
	if (pos == -1 || pos == size - 1) {
		erase_back();
	}
	else if (pos == 0) {
		erase_front();
	}
	else {
		node* tmp = head;
		while (--pos) {
			tmp = tmp->nxt;
		}
		node* del = tmp->nxt;
		tmp->nxt = tmp->nxt->nxt;
		delete del;
		size--;
	}
}

template<class T>
T& LinkedList<T>::operator[](int idx)//overload
{
	if (idx >= size)return cout << "\nERROR!!", this->operator[](0);//out of bounds 
	node* tmp = head;
	while (idx--) {
		tmp = tmp->nxt;
	}
	return tmp->valu;
}

template<class T>
T LinkedList<T>::get(int idx)
{
	return this->operator[](idx);
}

template<class T>
LinkedList<T>::~LinkedList()
{
	node* pre= head;
	node* cur = head->nxt;
	while (cur != NULL) {
		delete pre;
		pre = cur;
		cur = cur->nxt;
	}
	delete pre;
}
