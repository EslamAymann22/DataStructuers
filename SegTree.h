#pragma once
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

/// <summary>
/// using segment tree to get min value int range
/// updating segment of elements value in array
/// Segmant work with array base 1
/// </summary>

class SegTree
{
	vector <ll>seg, a,lazy;
	int n;
	void bld(int i, int l, int r);
	ll Get(int i, int l, int r, int st, int ed);
	void UpDate(int i,int l, int r, ll v,int st,int ed);
	void push(int i,int l,int r);
public:
	SegTree(vector<ll>&a, int n, ll INF = 1e17 + 5);
	ll INF;
	ll Get(int l, int r);
	void UpDate(int l, int r, ll v);
	~SegTree();
};

