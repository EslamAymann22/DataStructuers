
#include <iostream>
#include"stackLinkedList.h"
using namespace std;

bool open(char x) {
	return (x == '(' || x == '{' || x == '[' || x == '<');
}
bool ispra(char x) {
	return (x == '(' || x == '[' || x == '{' || x == '<' ||
		x == ')' || x == ']' || x == '}' || x == '>');
}
bool matching(char x, char y) {
	if (x == '(')return y == ')';
	if (x == '[')return y == ']';
	if (x == '{')return y == '}';
	if (x == '<')return y == '>';
}
bool AreBalanced(string s) {
	stackLinkedList<char>st;
	for (auto it : s) {
		if (!ispra(it))continue;
		if (open(it))st.push(it);
		else {
			if (st.Getsize() and matching(st.top(), it)) {
				st.pop();
			}
			else {
				st.clear();
				return 0;
			}
		}
	}
	return st.empty();
}
int main()
{

	string s;
	while (1) {
		cin >> s;
		cout << AreBalanced(s) << '\n';
	}

}
