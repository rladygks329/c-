#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;
};
void inorderBST(Node* root);
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
int main()
{
    Node* root = nullptr;
    insertBST(root,25);  inorderBST(root); cout << endl;
    insertBST(root,500); inorderBST(root); cout << endl;
    insertBST(root,49);  inorderBST(root); cout << endl;
    insertBST(root,17);  inorderBST(root); cout << endl;
    insertBST(root,403);  inorderBST(root); cout << endl;
    insertBST(root,29);  inorderBST(root); cout << endl;
    insertBST(root,105);  inorderBST(root); cout << endl;
    insertBST(root,39);  inorderBST(root); cout << endl;
    insertBST(root,66);  inorderBST(root); cout << endl;
    insertBST(root,305);  inorderBST(root); cout << endl;
    insertBST(root,44);  inorderBST(root); cout << endl;
    insertBST(root,19);  inorderBST(root); cout << endl;
    insertBST(root,441);  inorderBST(root); cout << endl;
    insertBST(root,390);  inorderBST(root); cout << endl;
    insertBST(root,12);  inorderBST(root); cout << endl;
    insertBST(root,81);  inorderBST(root); cout << endl;
    insertBST(root,50);  inorderBST(root); cout << endl;
    insertBST(root,100); inorderBST(root); cout << endl;
    insertBST(root,999);  inorderBST(root); cout << endl;
    cout << endl;

    deleteBST(root,25); inorderBST(root); cout << endl;
    deleteBST(root,500); inorderBST(root); cout << endl;
    deleteBST(root,49);  inorderBST(root); cout << endl;
    deleteBST(root,17);  inorderBST(root); cout << endl;
    deleteBST(root,403);  inorderBST(root); cout << endl;
    deleteBST(root,29);  inorderBST(root); cout << endl;
    deleteBST(root,105);  inorderBST(root); cout << endl;
    deleteBST(root,39);  inorderBST(root); cout << endl;
    deleteBST(root,66);  inorderBST(root); cout << endl;
    deleteBST(root,305);  inorderBST(root); cout << endl;
    deleteBST(root,44);  inorderBST(root); cout << endl;
    deleteBST(root,19);  inorderBST(root); cout << endl;
    deleteBST(root,441);  inorderBST(root); cout << endl;
    deleteBST(root,390);  inorderBST(root); cout << endl;
    deleteBST(root,12);  inorderBST(root); cout << endl;
    deleteBST(root,81);  inorderBST(root); cout << endl;
    deleteBST(root,50);  inorderBST(root); cout << endl;
    deleteBST(root,100); inorderBST(root); cout << endl;
    deleteBST(root,999);  inorderBST(root); cout << endl;
    cout << endl;
    insertBST(root,25);  inorderBST(root); cout << endl;
    insertBST(root,500); inorderBST(root); cout << endl;
    insertBST(root,49);  inorderBST(root); cout << endl;
    insertBST(root,17);  inorderBST(root); cout << endl;
    insertBST(root,403);  inorderBST(root); cout << endl;
    insertBST(root,29);  inorderBST(root); cout << endl;
    insertBST(root,105);  inorderBST(root); cout << endl;
    insertBST(root,39);  inorderBST(root); cout << endl;
    insertBST(root,66);  inorderBST(root); cout << endl;
    insertBST(root,305);  inorderBST(root); cout << endl;
    insertBST(root,44);  inorderBST(root); cout << endl;
    insertBST(root,19);  inorderBST(root); cout << endl;
    insertBST(root,441);  inorderBST(root); cout << endl;
    insertBST(root,390);  inorderBST(root); cout << endl;
    insertBST(root,12);  inorderBST(root); cout << endl;
    insertBST(root,81);  inorderBST(root); cout << endl;
    insertBST(root,50);  inorderBST(root); cout << endl;
    insertBST(root,100); inorderBST(root); cout << endl;
    insertBST(root,999);  inorderBST(root); cout << endl;
    cout << endl;
    deleteBST(root,999);  inorderBST(root); cout << endl;
    deleteBST(root,100); inorderBST(root); cout << endl;
    deleteBST(root,50);  inorderBST(root); cout << endl;
    deleteBST(root,81);  inorderBST(root); cout << endl;
    deleteBST(root,12);  inorderBST(root); cout << endl;
    deleteBST(root,390);  inorderBST(root); cout << endl;
    deleteBST(root,441);  inorderBST(root); cout << endl;
    deleteBST(root,19);  inorderBST(root); cout << endl;
    deleteBST(root,44);  inorderBST(root); cout << endl;
    deleteBST(root,305);  inorderBST(root); cout << endl;
    deleteBST(root,66);  inorderBST(root); cout << endl;
    deleteBST(root,39);  inorderBST(root); cout << endl;
    deleteBST(root,105);  inorderBST(root); cout << endl;
    deleteBST(root,29);  inorderBST(root); cout << endl;
    deleteBST(root,403);  inorderBST(root); cout << endl;
    deleteBST(root,17);  inorderBST(root); cout << endl;
    deleteBST(root,49);  inorderBST(root); cout << endl;
    deleteBST(root,500); inorderBST(root); cout << endl;
    deleteBST(root,25); inorderBST(root); cout << endl;

    return 0;
}
