/**
 * File processing, 2020
 * AVL.cpp
 * implementation of AVL tree
 */

#include <stdio.h>
/**
 * Node represents a single node in AVL tree.
 */
typedef struct Node {
  int         key, bf;
  struct Node *left, *right;
} Node;

typedef Node *Tree;

/**
 * getNode returns a new node.
 * @return a new node
 */
Node *getNode()
{
    return new Node;
}

Node *maxNode(Node* root )
{
    return (root->right == nullptr) ? root : maxNode(root->right);
}
Node* searchNode(Node *T, int key)
{
    Node* q = nullptr;
    Node* p = T;
    while( p!= nullptr)
    {
        if(key == p->key) return q;
        q = p;
        if(key < p->key) p = p->left;
        else p = p->right;
    }
    return q;
}

Node *minNode(Node* root)
{
    return (root->left == nullptr) ? root : minNode(root->left);
}

int noNodes(Node* root)
{
    return (root == nullptr) ? 0 : (noNodes(root->left)+noNodes(root->right)+1);//result;
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
    return ( p == nullptr) ? 0 : (Height(p->left) > Height(p->right) ? Height(p->left)+1 : Height(p->right)+1);
}
/**
 * updateBF updates balancing factors of nodes in T
 * and finds the unbalanced node nearest to y.
 * @param T: an AVL tree
 * @param y: the inserted/deleted node
 * @param x: the unbalanced node nearest to y
 * @param P: parent node of x
 */
void updateBF(Tree *T, Node *y, Node **x, Node **P) {
    Node * p = *T;
    Node * q = nullptr;
    while(q != y)
    {
        p->bf = Height(p->left) - Height(p->right);
        if(p->bf >= 2 || p->bf <= -2)
        {
            *x = p;
            *P = q;
        }
        q = p;
        if(y->key < p->key)
            p = p->left;
        else
            p = p->right;
    }
}

/**
 * rotateLL implements LL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateLL(Tree *T, Node *x, Node *P) {
    if(P == nullptr)
    {
        Node * B = x->left;
        x->left = B->right;
        B->right = x;
        *T = B;
        B->bf = Height(B->left) - Height(B->right);
        x->bf = Height(x->left) - Height(x->right);
    }
    else if(P->left == x){
        Node * B = x->left;
        x->left = B->right;
        B->right = x;
        P->left = B;

        P->bf = Height(P->left) - Height(P->right);
        x->bf = Height(x->left) - Height(x->right);
        B->bf = Height(B->left) - Height(B->right);
    }
    else
    {
        Node * B = x->left;
        x->left = B->right;
        B->right = x;
        P->right = B;

        P->bf = Height(P->left) - Height(P->right);
        x->bf = Height(x->left) - Height(x->right);
        B->bf = Height(B->left) - Height(B->right);
    }
}

/**
 * rotateRR implements RR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateRR(Tree *T, Node *x, Node *P) {
    if(P == nullptr)
    {
        Node* B = x->right;
        x->right = B->left;
        B->left = x;
        *T = B;
        B->bf = Height(B->left) - Height(B->right);
        x->bf = Height(x->left) - Height(x->right);
    }
    else if(P->left == x)
    {
        Node* B = x->right;
        x->right = B->left;
        B->left = x;
        P->left = B;

        P->bf = Height(P->left) - Height(P->right);
        x->bf = Height(x->left) - Height(x->right);
        B->bf = Height(B->left) - Height(B->right);
    }
    else
    {
        Node* B = x->right;
        x->right = B->left;
        B->left = x;
        P->right = B;

        P->bf = Height(P->left) - Height(P->right);
        x->bf = Height(x->left) - Height(x->right);
        B->bf = Height(B->left) - Height(B->right);
    }
}

/**
 * rotateLR implements LR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateLR(Tree *T, Node *x, Node *P) {
    rotateRR(&x,x->left,x);
    rotateLL(T,x,P);
}

/**
 * rotateRL implements RL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateRL(Tree *T, Node *x, Node *P) {
    rotateLL(&x,x->right,x);
    rotateRR(T,x,P);
}

/**
 * insertBST inserts newKey into T
 * and returns the inserted node.
 * @param T: a binary search tree
 * @param newKey: a key to insert
 * @return the inserted node
 */
Node *insertBST(Tree *T, int newKey) {
    Node* q = nullptr;
    Node* p = *T;
    while( p!= nullptr)
    {
        if(newKey == p->key) return nullptr;
        q = p;
        if(newKey < p->key) p = p->left;
        else p = p->right;
    }
    Node* newNode = getNode();
    newNode->key = newKey;
    newNode->bf = 0;
    newNode->right = nullptr;
    newNode->left = nullptr;
    if(q == nullptr)
        *T = newNode;
    else if(newKey < q->key)
        q->left = newNode;
    else
        q->right = newNode;
    return newNode;
}

int Diff(Node * n)
{
    return n == nullptr ? 0 : n->bf;
}
/**
 * insertAVL inserts newKey into T.
 * @param T: an AVL tree
 * @param newKey: a key to insert
 */
void insertAVL(Tree *T, int newKey) {
    Node * inserted_node = insertBST(T, newKey);
    Node * problem_node = nullptr;
    Node * parent_problem_node =nullptr;
    updateBF(T, inserted_node, &problem_node, &parent_problem_node);

    int factor = Diff(problem_node);
    if(1 < factor)
    {
        if(0 < Diff(problem_node->left))
        {
            printf("LL");
            rotateLL(T,problem_node,parent_problem_node);
        }
           else
           {
               printf("LR");
               rotateLR(T,problem_node,parent_problem_node);
           }
       }
       else if (-1 >factor)
       {
           if(0<Diff(problem_node->right))
           {
               printf("RL");
               rotateRL(T,problem_node,parent_problem_node);
           }
           else
           {
               printf("RR");
               rotateRR(T,problem_node,parent_problem_node);
           }
       }
       else
       {
           printf("NO");
       }
}

/**
 * deleteBST deletes deleteKey from T
 * and returns the parent node of the deleted node.
 * @param T: a binary search tree
 * @param deleteKey: a key to delete
 * @return the parent node of the deleted node
 */
Node *deleteBST(Tree *T, int deleteKey) {
    Node *q = nullptr;
    Node *p = *T;
    while(p != nullptr)
    {
        if(deleteKey == p->key) break;
        q = p;
        if(deleteKey < p->key) p = p->left;
        else p = p->right;
    }
    if(p == nullptr)
        return q;   /*can't find*/
    if( (q == nullptr) && (noNodes(p)==1)) /*only T exist*/
    {
        *T = nullptr;
        return q;
    }
    int degree = Degree(p);
    switch (degree) {
        case 0: /*delete reaf node*/
            if(q->left == p)
                q->left = nullptr;
            else
                q->right = nullptr;
            delete p;
            break;
        case 1:
            if(q == nullptr)
            {
                if(p ->left != nullptr) *T = p->left;
                else *T = p->right;
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
            else/*reft == right*/
            {
                if(noNodes(p->left) >=  noNodes(p->right))
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
            q = searchNode(*T , r->key);
            p->key = r->key;
            if(flag == 'L')
            {
                 deleteBST(&p->left, r->key);
            }
            else
            {
                  deleteBST(&p->right, r->key);
            }
            break;
    }
    return q;
}

/**
 * deleteAVL deletes deleteKey from T.
 * @param T: an AVL tree
 * @param deleteKey: a key to delete
 */
void deleteAVL(Tree *T, int deleteKey) {
    Node * root = *T;
    Node * deleted_node = deleteBST(T,deleteKey);
    Node * problem_node = nullptr;
    Node * parent_problem_node = nullptr;

    updateBF(T, deleted_node, &problem_node, &parent_problem_node);
    int factor = Diff(problem_node);
    if(1 < factor)
    {
        if(0 < Diff(problem_node->left))
        {
            printf("LL");
            rotateLL(T,problem_node,parent_problem_node);
        }
        else
        {
             printf("LR");
            rotateLR(T,problem_node,parent_problem_node);
        }
    }
    else if (-1 >factor)
    {
        if(0<Diff(problem_node->right))
        {
             printf("RL");
            rotateRL(T,problem_node,parent_problem_node);
        }
        else
        {
             printf("RR");
            rotateRR(T,problem_node,parent_problem_node);
        }
    }
    else
    {
         printf("NO");
    }
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
         printf("%d ",T->key);
        inorderAVL(T->right);
    }
}
/*void inorderAVLBF(Tree T)
{
    if( T!= nullptr)
    {
        inorderAVLBF(T->left);
        printf(" %d", (T->bf == Height(T->left)- Height(T->right)) );
        //printf(" %d",Height(T->left)- Height(T->right) );
        inorderAVLBF(T->right);
    }
}*/
int main() {
  /* Do not modify the code below */

  const int testcase[] = { 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 66, 10, 22, 30, 44, 55, 50, 60, 25, 49 };

  Tree T = NULL;

  // insertion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); insertAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }

  // deletion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); deleteAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }

  T = NULL;

  // reinsertion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); insertAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }

  // redeletion
  for (int i=19; 0<=i; i--) { printf("%d ", testcase[i]); deleteAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }
}
