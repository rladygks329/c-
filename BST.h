#ifndef _BST_H_
#define _BST_H_
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* right;
    Node* left;
};
void inorderBST(Node* root);
Node *maxNode(Node* root);
int noNodes(Node* root);
int Degree(Node* p);
int Height(Node *p);
void insertBST(Node* &root, int data);
void deleteBST(Node* &root, int data);
Node *minNode(Node* root);
#endif
