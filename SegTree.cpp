#include "SegTree.h"


SegTree::SegTree(vector<ll>&a, int n,ll INF) {
	this->a = a;
	this->n = n;
	this->INF = INF;
	seg.resize((n << 2) + 5, INF);
	lazy.resize((n << 2) + 5, INF);
	bld(1, 1, n);
}

void SegTree::bld(int i, int l, int r)
{
	if (l == r) {
		seg[i] = a[l];
		return;
	}
	int mid = l + r >> 1;
	bld(i * 2, l, mid);
	bld(i * 2 + 1, mid + 1, r);
	seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
}

ll SegTree::Get(int i, int l, int r, int st, int ed)
{

	// to set lazy array value to main array
	push(i, l, r);
	//segment out of range 
	//Returns a large value so as not to affect the answer
	if (l > ed || r < st)return INF;

	// segment in requested range
	if (l >= st and r <= ed)return seg[i];

	int mid = l + r >> 1;
	return min(
		Get(i * 2, l, mid, st, ed),
		Get(i * 2 + 1, mid + 1, r, st, ed)
	);

}

void SegTree::UpDate(int i, int l, int r, ll v, int st, int ed)
{
	push(i, l, r);
	if (l > ed || r < st)return;
	if (l >= st and r <= ed)return lazy[i] = v, void();
	int mid = l + r >> 1;
	UpDate(i * 2, l, mid, v, st, ed);
	UpDate(i * 2, mid + 1, r, v, st, ed);
	seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
}

void SegTree::push(int i,int l,int r) {
	if (lazy[i] == INF)return;
	seg[i] = lazy[i];
	if (l != r) {
		lazy[i * 2] =
			lazy[i * 2 + 1] = lazy[i];
	}
	lazy[i] = INF;
}

ll SegTree::Get(int l, int r)
{
	return Get(1, 1, n, l, r);
}

void SegTree::UpDate(int l, int r, ll v)
{
	return UpDate(1, 1, n, v, l, r);
}

SegTree::~SegTree()
{
	lazy.clear();
	seg.clear();
}
