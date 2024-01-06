#include "LinkedList.h"

LinkedList::LinkedList() {
	head = new node;
	head->nxt = NULL;
	size = 0;
	// head == first element
}

bool LinkedList::empty()
{
	return (size == 0);
}

void LinkedList::push_front(int value)
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

void LinkedList::push_back(int value)
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

void LinkedList::erase_front()
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

void LinkedList::erase_back()
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

void LinkedList::insert(int val, int pos)
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

void LinkedList::display()
{
	node* tmp = head;
	int sz = size;
	// while (tmp!=NULL) ==> make a problem because if size == 0 and head still have value
	while (sz--) {
		cout << tmp->valu << ' ';
		tmp = tmp->nxt;
	}
}

void LinkedList::erase(int pos)
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

int LinkedList::operator[](int idx)//overload
{
	if (idx >= size)return cout << "\nERROR!!", -1;//out of bounds 
	node* tmp = head;
	while (idx--) {
		tmp = tmp->nxt;
	}
	return tmp->valu;
}

int LinkedList::get(int idx)
{
	return this->operator[](idx);
}

LinkedList::~LinkedList()
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