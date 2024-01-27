#include <iostream>
#include "Trie.h"
using namespace std;

int main() {
	Trie x;
	
	x.insert("abc");
	x.insert("abcd");
	x.insert("abcd");
	x.insert("abcd");

	cout << x.Find("abc") << " Time \n";
	x.erase("abc");
	x.erase("abc");
	cout << x.Find("abc") << " Time \n";
	cout<<x.FindPrefix("abc");
}