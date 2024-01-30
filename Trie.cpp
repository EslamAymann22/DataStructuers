#include "Trie.h"

class Trie::node {
public:
	char x;
	int fr;
	int IsLeaf;
	node* nxt[26];
	node() {
		memset(nxt, 0, sizeof nxt);
		fr = 0;
		IsLeaf = 0;
	}
};
Trie::Trie() {
	head = new node;
};
void Trie::insert(string s)
{

	int i = 0, n = s.size();
	node* cur = head;
	while (i < n) {
		if (cur->nxt[s[i] - 'a'] != NULL) {
			cur = cur->nxt[s[i] - 'a'];
			i++;
		}
		else {
		//cout << s[i] << '\n';
			cur->nxt[s[i] - 'a'] = new node;
			cur = cur->nxt[s[i] - 'a'];
			cur->x = s[i];
			i++;
		}
		cur->fr++;
		if (i == n)cur->IsLeaf++;
	}
}

int Trie::Find(string s)
{
	int i = 0, n = s.size();
	node* cur = head;
	while (i < n) {

		if (cur->nxt[s[i] - 'a'] != nullptr) {
			cur = cur->nxt[s[i] - 'a'];
			i++;
		}
		else {
			return 0;
		}
	}
	return cur->IsLeaf;
	
}

int Trie::FindPrefix(string s) {
	int i = 0, n = s.size();
	node* cur = head;
	while (i < n) {

		if (cur->nxt[s[i] - 'a'] != nullptr) {
			cur = cur->nxt[s[i] - 'a'];
			i++;
		}
		else return 0;
	}
	return cur->fr;
}

void Trie::erase(string s) {
	if (!Find(s))return;
	int i = 0, n = s.size();
	node* cur = head, *prev = head;
	while (i < n) {
		prev = cur;
		cur = cur->nxt[s[i] - 'a'];
		cur->fr--;
		if (prev->fr == 0 and prev != head) {
			delete prev;
		}
		i++;
	}
	if (cur->IsLeaf)cur->IsLeaf--;
	if (cur->fr == 0 and cur != head)delete cur;
}

