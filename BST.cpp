#include "BST.h"

BST::BST(int val) :size(1), root(new node(val)) {}

void BST::insert(int val)
{
    node* cur = root;
    node* add = new node(val);
    while (1) {
        if (val > cur->val) {
            if (cur->right == NULL) {
                add->par = cur;
                cur->right = add;
                break;
            }
            else cur = cur->right;
        }
        else {
            if (cur->left == NULL) {
                add->par = cur;
                cur->left = add;
                break;
            }
            else cur = cur->left;
        }
    }
    size++;
}

void BST::PreOrder(node* cur)
{
    if (cur == NULL) {
        cur = root;
    }
    cout << cur->val << ' ';
    if (cur->left != NULL)PreOrder(cur->left);
    if (cur->right != NULL)PreOrder(cur->right);
}

int BST::GetSize()
{
    return size;
}

void BST::InOrder(node* cur)
{
    if (cur == NULL) {
        cur = root;
    }
    if (cur->left != NULL)InOrder(cur->left);
    cout << cur->val << ' ';
    if (cur->right != NULL)InOrder(cur->right);
}

void BST::PostOrder(node* cur)
{
    if (cur == NULL) {
        cur = root;
    }
    if (cur->left != NULL)PostOrder(cur->left);
    if (cur->right != NULL)PostOrder(cur->right);
    cout << cur->val << ' ';
}

void BST::Display()
{
    InOrder();
}

node BST::GetRoot()
{
    return *root;
}

void BST::remove(int val)
{
    node* del = search(val, root);
    if (del == NULL)return;
    if (del == root) {

    }
    else  if (del->left != NULL and del->right != NULL) {// make a Successor root of subtree

    }
    else if (del->left != NULL) {
        if (del->val > del->par->val) {
            del->par->right = del->left;
        }
        else {
            del->par->left = del->left;
        }
    }
    else if (del->right != NULL) {
        if (del->val > del->par->val) {
            del->par->right = del->right;
        }
        else {
            del->par->left = del->right;
        }
    }
    else {// leave
         if (del->val > del->par->val) {
             del->par->right = NULL;
         }
         else {
             del->par->left = NULL;
        }
    }
    delete del;
    size--;
}

bool BST::search(int val) {
    return search(val, root) != NULL;
}


node* BST::search(int val, node* cur) {
    if (cur == NULL)return cur;
    if (cur->val == val)return cur;
    else if (val > cur->val) {
        return search(val, cur->right);
    }
    else {
        return search(val, cur->left);
    }
}
