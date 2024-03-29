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

int BST::Successor(int val)
{
    node* cur = search(val, root);
    if (cur == NULL)return -1;
    if (cur->right != NULL) {
        return (GetMin(cur->right));
    }
    else if (cur->par == NULL) {
        return -1;
    }
    else {
        // left child
        if (cur->par->val > cur->val)return cur->par->val;
        // else right child
        while (cur->par != NULL and cur->par->val <= cur->val)cur = cur->par;
        if (cur->par == NULL)return -1;
        return cur->par->val;
    }
}

int BST::Predecessor(int val)
{
    node* cur = search(val, root);
    if (cur == NULL)return -1;
    if (cur->left != NULL) {
        return (GetMax(cur->left));
    }
    else if (cur->par == NULL) {
        return -1;
    }
    else {
        // left child
        if (cur->par->val < cur->val)return cur->par->val;
        // else right child
        while (cur->par != NULL and cur->par->val > cur->val)cur = cur->par;
        if (cur->par == NULL)return -1;
        return cur->par->val;
    }
}

int BST::GetMax(node* cur)
{
    if (cur == NULL)cur = root;
    while (cur->right != NULL)cur = cur->right;
    return cur->val;
}

int BST::GetMin(node* cur)
{
    if (cur == NULL)cur = root;
    while (cur->left != NULL)cur = cur->left;
    return cur->val;
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
    if (del == root and (del->left==NULL||del->right==NULL)) {
        if (del->left != NULL) {
            root = del->left;
            root->par = NULL;
            delete del;
        }
    }
    else  if (del->left != NULL and del->right != NULL) {// make a Successor root of subtree
        node* cur = del->right;
        while (cur->left != NULL)cur = cur->left;
        int tmp = cur->val;// when call remove cur will be deleted
        remove(cur->val);
        del->val = tmp;
    }
    else if (del->left != NULL) {
        if (del->val > del->par->val) {
            del->par->right = del->left;
            del->left->par = del->par;
        }
        else {
            del->par->left = del->left;
            del->left->par = del->par;
        }
        delete del;
    }
    else if (del->right != NULL) {
        if (del->val > del->par->val) {
            del->par->right = del->right;
            del->right->par = del->par;
        }
        else {
            del->par->left = del->right;
            del->right->par = del->par;
        }
        delete del;
    }
    else {// leave
        if (del->val > del->par->val) {
            del->par->right = NULL;
        }
        else {
            del->par->left = NULL;
        }
        delete del;
    }
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

void BST::clear(node* cur)
{
    if (cur == NULL)cur = root;
    if (cur->left)clear(cur->left);
    if (cur->right)clear(cur->right);
    if (cur != root)
        delete cur;
    else {
        root->left = root->right = NULL;
    }
}
BST::~BST()
{
    clear();
    delete root;
}