#pragma once
#include<iostream>
#include<string>
using namespace std;
class Trie
{
public:
	class node;
	node* head;
	Trie();
	void insert(string s);
	int Find(string s);
	int FindPrefix(string s);
	void erase(string s);

};

