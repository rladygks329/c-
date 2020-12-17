/*
 * File processing, 2020
 * btree.cpp
 * implementation of B-tree
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<stack>
using namespace std;
/**
 * BTNode represents a single node in B-tree.
 */
typedef struct BTNode {
  int           n,  *K;
  struct BTNode **P;
} BTNode;

/**
 * getBTNode retruns a new BTNode.
 * @param m: number of branch points in B-tree
 * @return a new BTNode
 */
BTNode *getBTNode(int m) {
  BTNode *node  = (BTNode *)malloc(sizeof(BTNode));
  node -> n     = 0;
  node -> K     = (int *)malloc(sizeof(int) * (m-1));
  node -> P     = (BTNode **)malloc(sizeof(BTNode *) * m);

  for(int i=0;i<m;i++)
  {
      node -> P[i] =  NULL;
  }
  return node;
}

typedef BTNode *BTree;
/**
 * insertBT inserts newKey into T.
 * @param T: a B-tree
 * @param m: number of branch points in B-tree
 * @param newKey: a key to insert
 */
void insertBT(BTree *T, int m, int newKey) {
    if(*T == nullptr)//empty
    {
        *T  = getBTNode(m);
        (*T) ->  n = 1;
        (*T) ->  K[0] = newKey;
        return;
    }
    BTNode * x = *T;
    int index;
    stack<BTNode*> path;
    stack<int> pathi;
    while( x != NULL)
    {
        int i = 0;
        while( i< x->n && newKey > x->K[i])
            i++;
        path.push(x);
        pathi.push(i);
        x = x->P[i];
    }//end location finding

    BTNode * tempNode = getBTNode(m+1);
    BTNode *y = getBTNode(m);
    stack<BTNode *> split;
    bool finished = false;

    x = path.top();
    path.pop();
    index = pathi.top();
    pathi.pop();

    while(!finished){
        if(x->n < m-1 ) // can insert without split;
        {
            for(int i = x->n -1; i >=  index; i--) //n ->index make a space
            {
                x->K[i+1] = x->K[i];
                x->P[i+1] = x->P[i];
            }
            x->K[index] = newKey; //insert
            if(!split.empty())
            {
                x->P[index+1] = split.top();
                split.pop();
            }
            x->n++;
            finished = true;
            break;
        }
        else
        {
            if(x->P[0] == NULL) //leaf_node
            {
                for(int i = 0; i<index; i++)
                {
                    tempNode ->K[i] = x->K[i];
                }
                tempNode->K[index] = newKey;
                for(int i = index+1;i<m;i++)
                {
                    tempNode ->K[i] = x->K[i-1];
                }
            }
            else//not leaf_node
            {
                for(int i = 0; i<index; i++)
                {
                    tempNode ->K[i] = x->K[i];
                    tempNode ->P[i] = x->P[i];
                }
                tempNode ->K[index] = newKey;
                tempNode->P[index] = x->P[index];

                tempNode ->K[index+1] = x->K[index+1];
                tempNode ->P[index+1] = split.top();
                split.pop();
                for(int i =index+2;i<m;i++)
                {
                    tempNode->K[i] = x->K[i-1];
                    tempNode->P[i] = x->P[i-1];
                }
            }
        }
        //split
        int mid = m/2;
        newKey = tempNode->K[mid];
        for(int i =0; i<mid;i++)
        {
            x->K[i] = tempNode ->K[i];
            x->P[i] = tempNode ->P[i];
        }
        for(int i = mid; i<m; i++)
        {
            y ->K[i-mid] = tempNode ->K[i+1];
            y->P[i-mid] = tempNode ->P[i+1];
            y->n++;

            x->K[i] = 0;
            x->P[i] = NULL;
        }
        x->n = mid-1;
        split.push(y);
        if(!path.empty())
        {
            x = path.top();
            path.pop();
            index = pathi.top();
            pathi.pop();
        }
        else
        {
            (*T) = getBTNode(m);
            (*T) ->K[0] = newKey;
            (*T) ->P[0] = x;
            (*T) ->P[1] = y;
            finished = true;
        }
    }
}

/**
 * deleteBT deletes oldKey from T.
 * @param T: a B-tree
 * @param m: number of branch points in B-tree
 * @param oldKey: a key to delete
 */
void deleteBT(BTree *T, int m, int oldKey) {
  /* write your code here */
}

/**
 * inorderBT implements inorder traversal in T.
 * @param T: a B-tree
 */
void inorderBT(BTree T) {
    int i = 0;
    if(T == NULL) return;
    for(i;i<T->n;i++)
    {
        inorderBT(T->P[i]);
        printf("%d ",T->K[i]);
    }
    inorderBT(T->P[i]);
}

int main() {
  /* do not modify the code below */

  int insertTestCases[] = { 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 66, 10, 22, 30, 44, 55, 50, 60, 100, 28, 18, 9, 5, 17, 6, 3, 1, 4, 2, 7, 8, 73, 12, 13, 14, 16, 15, 25, 24, 28, 45, 49, 42, 43, 41, 47, 48, 46, 63, 68, 61, 62, 64, 69, 67, 65, 54, 59, 58, 51, 53, 57, 52, 56, 83, 81, 82, 84, 75, 89 };
  int deleteTestCases[] = { 66, 10, 22, 30, 44, 55, 50, 60, 100, 28, 18, 9, 5, 17, 6, 3, 1, 4, 2, 7, 8, 73, 12, 13, 14, 16, 15, 25, 24, 28, 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 45, 49, 42, 43, 41, 47, 48, 46, 63, 68, 53, 57, 52, 56, 83, 81, 82, 84, 75, 89, 61, 62, 64, 69, 67, 65, 54, 59, 58, 51 };

  BTree T = NULL;

  for (int tC : insertTestCases) { insertBT(&T, 3, tC); inorderBT(T); printf("\n"); }
  for (int tC : deleteTestCases) { deleteBT(&T, 3, tC); inorderBT(T); printf("\n"); }

  T = NULL;

  for (int tC : insertTestCases) { insertBT(&T, 4, tC); inorderBT(T); printf("\n"); }
  for (int tC : deleteTestCases) { deleteBT(&T, 4, tC); inorderBT(T); printf("\n"); }
}
