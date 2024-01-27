#pragma once
#include <vector>
using namespace std;

template <class intt>
class MinHeap
{
	vector<intt>heap;
	int left(int node);
	int right(int node);
	int parent(int node);
	void ReHeapUp(int node);
	void ReHeapDown(int node);
public:

	intt top();
	void pop();
	int size();
	void push(intt v);
};

template<class intt>
inline int MinHeap<intt>::left(int node)
{
	int ret = node * 2 + 1;
	if (ret >= heap.size())return -1;
	return ret;
}

template<class intt>
inline int MinHeap<intt>::right(int node)
{
	int ret = node * 2 + 2;
	if (ret >= heap.size())return -1;
	return ret;
}

template<class intt>
inline int MinHeap<intt>::parent(int node)
{
	return (node - 1) / 2;
}

template<class intt>
inline void MinHeap<intt>::ReHeapUp(int node)
{
	if (node == 0)return;
	int p = parent(node);
	if (heap[node] < heap[p]) {
		swap(heap[node], heap[p]);
		ReHeapUp(p);
	}
}


template<class intt>
inline void MinHeap<intt>::ReHeapDown(int node) {
	int l = left(node);
	int r = right(node);
	int mn = l;
	if (l == -1)return;
	if (r != -1) {
		if (heap[l] > heap[r])mn = r;
	}
	if (mn != -1 and heap[node] > heap[mn]) {
		swap(heap[node], heap[mn]);
		ReHeapDown(mn);
	}
}

template<class intt>
inline intt MinHeap<intt>::top()
{
	if (heap.size() == 0)return -1;
	return heap[0];
}

template<class intt>
inline void MinHeap<intt>::pop()
{
	heap[0] = heap.back();
	heap.pop_back();
	ReHeapDown(0);
}

template<class intt>
inline int MinHeap<intt>::size()
{
	return heap.size();
}

template<class intt>
inline void MinHeap<intt>::push(intt v)
{
	heap.push_back(v);
	ReHeapUp(size() - 1);
}
