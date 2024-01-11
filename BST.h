#pragma once
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int val;
        node* left;
        node* right;
        node* par;

        node(int val = -1, node* left = NULL, node* right = NULL, node* par = NULL) :
            val(val), left(left), right(right), par(par) {}
    };
class BST {

    node* root;
    int size;
public:
    BST(int val);
    void insert(int val);
    void PreOrder(node* cur = NULL);
    void InOrder(node* cur = NULL);
    void PostOrder(node* cur = NULL);
    void Display();
    node GetRoot();
    void remove(int val);
    node* search(int val, node* cur);
    bool search(int val);
    int GetSize();
    int Successor(int val);//first element greater than val
    int Predecessor(int val);//first element smaler  than val
    int GetMax(node* cur = NULL);
    int GetMin(node* cur = NULL);
    void clear(node*cur=NULL);
    ~BST();
};
