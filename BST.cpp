#include "BST.h"

Node *maxNode(Node* root )
{
    Node* result = nullptr;
    if(root != nullptr)
    {
        if(root ->right == nullptr)
        {
            result = root;
        }
        else
        {
            result = maxNode(root->right);
        }
    }
    return result;
}
Node *minNode(Node* root)
{
    Node* result = nullptr;
    if(root != nullptr)
    {
        if(root ->left == nullptr)
        {
            result = root;
        }
        else
        {
            result = minNode(root->left);
        }
    }
    return result;
}
int noNodes(Node* root)
{
    int result = 0;
    if(root != nullptr)
    {
        result = noNodes(root->left) + noNodes(root->right) + 1;
    }
    else
    {
        return 0;
    }
    return result;
}
int Degree(Node* p)
{
    if(p->left == nullptr && p->right == nullptr) return  0;
    if(p->left == nullptr || p->right == nullptr) return 1;
    if(p->left != nullptr && p->right != nullptr) return 2;
    return -1;
}
int Height(Node *p)
{
    int p_left, p_right;
    if(p->left == nullptr) p_left = 0;
    else p_left = Height(p->left) +1;

    if(p->right == nullptr) p_right = 0;
    else p_right = Height(p->right) +1;

    return (p_left > p_right) ? p_left : p_right;
}
void insertBST(Node* &root, int data)
{
    Node* q = nullptr;
    Node* p = root;
    while( p!= nullptr)
    {
        if(data == p->data) return;
        q = p;
        if(data < p->data) p = p->left;
        else p = p->right;
    }
    Node* newNode = new Node;
    newNode->data = data;
    newNode->right = nullptr;
    newNode->left = nullptr;
    if(q == nullptr)
    {
        root = newNode;
    }
    else if(data < q->data)
    {
        q->left = newNode;
    }
    else
    {
        q->right = newNode;
    }
}
void deleteBST(Node* &root, int data)
{
    Node *q = nullptr;
    Node* p = root;


    while(p != nullptr)
    {
        if(data == p->data) break;
        q = p;
        if(data < p->data) p = p->left;
        else p = p->right;
    }
    if(p == nullptr)    return; //can't find
    if( (q == nullptr) && (noNodes(p)==1)) //only root exist
    {
        root = nullptr;
        return;
    }
    int degree = Degree(p);
    switch (degree) {
        case -1:
            return;
            break;
        case 0: //delet reaf node
            if(q->left == p)
                q->left = nullptr;
            else
                q->right = nullptr;
            delete p;
            break;
        case 1:
            if(q == nullptr)
            {
                if(p ->left != nullptr) root = p->left;
                else root = p->right;
                delete p;
                return;
            }
            if(p->left != nullptr)
            {
                if(q->left == p)
                    q->left = p->left;
                else
                    q->right = p->left;
            }
            else
            {
                if(q->left == p)
                    q->left = p->right;
                else
                    q->right = p->right;
            }
            delete p;
            break;
        case 2:
            Node *r = nullptr;
            char flag;
            int left = Height(p->left);
            int right = Height(p->right);
            if(left > right)
            {
                r = maxNode(p->left);
                flag = 'L';
            }
            else if(left <right)
            {
                r = minNode(p->right);
                flag = 'R';
            }
            else//reft == right
            {
                if(noNodes(p->left) >= noNodes(p->right))
                {
                    r = maxNode(p->left);
                    flag = 'L';
                }
                else
                {
                    r = minNode(p->right);
                    flag = 'R';
                }
            }
            p->data = r->data;
            if(flag == 'L')
            {
                deleteBST(p->left, r->data);
            }
            else
            {
                deleteBST(p->right, r->data);
            }
            break;
    }
}
void inorderBST(Node* root)
{
    if(root != nullptr)
    {
        inorderBST(root->left);
        cout << root->data <<" ";
        inorderBST(root->right);
    }
}
