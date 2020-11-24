/**
 * File processing, 2020
 * AVL.cpp
 * implementation of AVL tree
 */
#include <stdio.h>
#include <iostream>
using namespace std;
// Node represents a single node in AVL tree.
typedef struct Node {
  int key, bf;
  struct Node *left, *right;
} Node;

/**
 * getNode returns a new node.
 * @return a new node
 */
 Node *getNode()
 {
     Node *newNode = new Node;
     newNode ->key = 0;
     newNode ->bf = 0;
     newNode->left = nullptr;
     newNode->left = nullptr;
     return newNode;
 }

typedef Node *Tree;

// rotationType represents the rotation types of AVL tree.
typedef enum { LL, RR, LR, RL } rotationType;
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
    if(p == nullptr)
        return 0;
    else
    {
        int p_left = Height(p->left);
        int p_right = Height(p->right);
        return (p_left > p_right) ? p_left+1 : p_right+1;
    }
}
void insertBST(Node* &root, int key)
{
    Node* q = nullptr;
    Node* p = root;
    while( p!= nullptr)
    {
        if(key == p->key) return;
        q = p;
        if(key < p->key) p = p->left;
        else p = p->right;
    }
    Node* newNode = getNode();
    newNode->key = key;
    newNode->bf = 0;
    newNode->right = nullptr;
    newNode->left = nullptr;
    if(q == nullptr)
    {
        root = newNode;
    }
    else if(key < q->key)
    {
        q->left = newNode;
    }
    else
    {
        q->right = newNode;
    }
}
Node* deleteBST(Node* &root, int key)
{
    Node *q = nullptr;
    Node* p = root;
    while(p != nullptr)
    {
        if(key == p->key) break;
        q = p;
        if(key < p->key) p = p->left;
        else p = p->right;
    }
    if(p == nullptr)    return q; //can't find
    if( (q == nullptr) && (noNodes(p)==1)) //only root exist
    {
        root = nullptr;
        return q;
    }
    int degree = Degree(p);
    switch (degree) {
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
                return q;
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
            p->key = r->key;
            if(flag == 'L')
            {
                q = deleteBST(p->left, r->key);
            }
            else
            {
                q = deleteBST(p->right, r->key);
            }
            break;
    }
    return q;
}
/**
 * insertBST inserts newKey into T.
 * @param T: a binary search tree
 * @param newKey: a key to insert
 */
//void insertBST(Tree *T, int newKey) {
//  /* write your code here */
//}

/**
 * deleteBST deletes deleteKey from T.
 * @param T: a binary search tree
 * @param deleteKey: a key to delete
 */
//void deleteBST(Tree *T, int deleteKey) {
 // /* write your code here */
//}

/**
 * updateBF updates the balancing factors on the path from y to the root node and
 * returns the nearest unbalanced node.
 * @param T: an AVL tree
 * @param y: a node
 * @return the unbalanced node nearest to y
 */

Node* updateBF(Tree T, Node* y) {
    Node * p = T;
    Node * q = nullptr;
    while(p != y)
    {
        p->bf = Height(p->left) - Height(p->right);
        if(p->bf == 2 || p->bf == -2) q = p;
        if(y->key < p->key) p = p->left;
        else p = p->right;
    }
    if( p == y)
    {
        p->bf = Height(p->left) - Height(p->right);
        if(p->bf == 2 || p->bf == -2)
            return p;
    }
    return q;
}
Node * searchNode(Tree T, int key)
{
    Node *q = nullptr;
    Node* p = T;
    while(p != nullptr)
    {
        if(key == p->key) return p;
        q = p;
        if(key < p->key) p = p->left;
        else p = p->right;
    }
    return q;
}

void updateAVLBF(Tree T)
{
    if( T!= nullptr)
    {
        updateAVLBF(T->left);
        T->bf = Height(T->left)-Height(T->right);
        updateAVLBF(T->right);
    }
}


/**
 * rotateLL implements LL rotation in subtree rooted with x.
 * @param x: root node of subtree
 */
void rotateLL(Node *x) {
    Node * temp = x->left;
    x->left = temp->left;

    temp->left =temp->right;
    temp->right = x->right;
    x->right = temp;

    //change
    int a = x->key;
    x->key = temp->key;
    temp->key = a;
    updateAVLBF(x);
}

/**
 * rotateRR implements RR rotation in subtree rooted with x.
 * @param x: root node of subtree
 */
void rotateRR(Node *x) {
    Node * temp = x->right;
    x->right = temp->right;
    temp->right = temp->left;
    temp->left = x->left;
    x->left = temp;

    int a = x->key;
    x->key = temp->key;
    temp->key = a;
    updateAVLBF(x);
}

/**
 * rotateLR implements LR rotation in subtree rooted with x.
 * @param x: root node of subtree
 */
void rotateLR(Node *x) {
    rotateRR(x->left);
    rotateLL(x);
}

/**
 * rotateRL implements RL rotation in subtree rooted with x.
 * @param x: root node of subtree
 */
void rotateRL(Node *x) {
    rotateLL(x->right);
    rotateRR(x);
}

/**
 * insertAVL inserts newKey into T.
 * @param T: an AVL tree
 * @param newKey: a key to insert
 * @return rotation type
 */
//rotationType
void insertAVL(Tree &T, int newKey) {
    insertBST(T, newKey);
    Node * inserted_node = searchNode(T,newKey);
    Node * problem_node = updateBF(T,inserted_node);
    if(problem_node == nullptr)
    {
        cout << " NO :";
        return;
    }
    int bf = problem_node->bf;
    if(bf == 2)
    {
        if(problem_node->left->bf == 1)
        {
            rotateLL(problem_node);
            cout <<" LL :";
        }
        else
        {
             rotateLR(problem_node);
             cout <<" LR :";
         }
    }
    else if(bf == -2)
    {
        if(problem_node->right->bf == -1)
        {
            rotateRR(problem_node);
            cout <<" RR :";
        }
        else
        {
            rotateRL(problem_node);
            cout <<" RL :";
        }
    }
}

/**
 * deleteAVL deletes deleteKey from T.
 * @param T: an AVL tree
 * @param deleteKey: a key to delete
 * @return rotation type
 */
void deleteAVL(Tree &T, int deleteKey) {
    Node * deleted_node = deleteBST(T,deleteKey);
    if(deleted_node == nullptr)
    {
        cout << " NO :"; //root
        return;
    }
    Node * problem_node = updateBF(T,deleted_node);
    if(problem_node == nullptr)
    {
        cout << " NO :";/* problem_node dosen't exsist*/
        return;
    }
    int bf = problem_node->bf;
    if(bf == 2)
    {
        if(problem_node->left->bf == 1)
        {
            rotateLL(problem_node);
            cout <<" LL :";
        }
        else
        {
             rotateLR(problem_node);
             cout <<" LR :";
         }
    }
    else if(bf == -2)
    {
        if(problem_node->right->bf == -1)
        {
            rotateRR(problem_node);
            cout <<" RR :";
        }
        else
        {
            rotateRL(problem_node);
            cout <<" RL :";
        }
    }
    updateBF(T, problem_node);
}

/**
 * inorderAVL implements inorder traversal in T.
 * @param T: an AVL tree
 */
void inorderAVL(Tree T)
{
    if( T!= nullptr)
    {
        inorderAVL(T->left);
        cout << T->key <<" ";
        inorderAVL(T->right);
    }
}
void inorderAVLBF(Tree T)
{
    if( T!= nullptr)
    {
        inorderAVLBF(T->left);
        //cout << Height(T->left)- Height(T->right) <<" ";
        cout << (T->bf == Height(T->left)- Height(T->right)) <<" ";
        inorderAVLBF(T->right);
    }
}
int main() {
  /* do not modify the code below */

  int testcase[] = { 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 66, 10, 22, 30, 44, 55, 50, 60, 25, 49 };

  const char *rotationTypes[] = { "LL", "RR", "LR", "RL" };

  Tree T = NULL;

  // insertion
  for (int i=0; i<20; i++)
  {
      cout << testcase[i];
      insertAVL(T,testcase[i]);
      inorderAVL(T);
      cout <<endl;
   }
 // deletion
   for (int i=0; i<20; i++)
   {
       cout << testcase[i];
       deleteAVL(T,testcase[i]);
       inorderAVL(T);
       cout << endl;
   }

  T = NULL;

  // reinsertion
  for (int i=0; i<20; i++)
  {
      cout << testcase[i];
      insertAVL(T,testcase[i]);
      inorderAVL(T);
      cout <<endl;
  }
  // redeletion
  for (int i=19; 0<=i; i--)
  {
      cout << testcase[i];
      deleteAVL(T,testcase[i]);
      inorderAVL(T);
       cout <<endl;
   }
}
