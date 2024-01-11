// DataSrucures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include"MyVectorr.h"
#include"stackarray.h"
#include"BST.h"
//#include"BST.h"
using namespace std;
int main()
{
	BST a(40);	
	a.insert(60);
	a.insert(30);
	a.insert(35);
	a.insert(10);
	a.insert(15);
	a.insert(5);
	a.insert(31);
	a.insert(39);
	a.insert(50);
	a.insert(70);
	a.insert(65);
	a.insert(80);
	a.insert(41);
	a.insert(55);
	a.Display(); cout << '\n';
	a.remove(80);
	a.Display(); cout << '\n';
	a.insert(90);
	a.Display(); cout << '\n';
	cout << (a.search(80) ? "Yes" : "No") << '\n';
	while (1) {
		int x; cin >> x;
		cout << a.Successor(x) << '\n';
		cout << a.Predecessor(x) << '\n';

	}
}
