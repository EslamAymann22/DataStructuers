#include<bits/stdc++.h>
#include"SegTree.h"
typedef long long     ll;
using namespace std;


int main() {
	int n; 
	cout << "Enter array size : "; cin >> n;
	vector<ll>a(n + 5);
	cout << "Enter array value :\n";
	for (int i = 1; i <= n; i++)cin >> a[i];
	SegTree seg(a, n);
	while (1) {
		int op;
		cout << "1 to get\n2 to update\n\n";
		cout << "Enter operation : ";
		cin >> op;
		if (op == 1) {
			cout << "enter l , r : ";
			int l, r; cin >> l >> r;
			cout << "Min is : " << seg.Get(l, r) << '\n';
		}
		else if (op == 2) {
			cout << "Enter l , r , NewValue : ";
			int l, r, v; cin >> l >> r >> v;
			seg.UpDate(l, r, v);
		}
		else break;
	}
}