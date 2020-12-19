/*
 * File processing, 2020
 * btree.cpp
 * implementation of B-tree
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<string.h>
#include<stack>
#include<algorithm>
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
  node -> K = (int *)calloc(m-1,sizeof(int));
  node -> P = (BTNode**)calloc(m, sizeof(BTNode*));
  return node;
}

typedef BTNode *BTree;
void printBTNode(BTNode* a)
{
    if(a!= NULL)
    {
        for(int i=0;i<a->n;i++)
        {
            //printBTNode(a->P[i]);
            cout <<a->K[i]<<" ";
        }
        //printBTNode(a->P[a->n]);
    }
}
/**
 * insertBT inserts newKey into T.
 * @param T: a B-tree
 * @param m: number of branch points in B-tree
 * @param newKey: a key to insert
 */
void insertBT(BTree *T, int m, int newKey) {
    if(*T == nullptr)//empty
    {
        (*T)  = getBTNode(m);
        (*T) ->  n = 1;
        (*T) ->  K[0] = newKey;
        return;
    }

    //searching
    BTNode * x = *T;
    int index;
    stack<BTNode*> path;

    while( x != NULL)
    {
        int i = 0;
        while( i< x->n && newKey > x->K[i])
            i++;
        if(i <x->n && newKey == x->K[i]) return;
        path.push(x);
        x = x->P[i];
    }
    stack<BTNode*> split;

    do{
        x = path.top();
        path.pop();
        index =0;
        for(int i=0;i<x->n;i++){ if(newKey > x->K[i]) index++;}
        if(x->n < m-1 ) // can insert without split;
        {
            memmove(x->K+index+1,x->K+index,sizeof(int)*(x->n-index));
            x->K[index] = newKey;
            memmove(x->P+index+2,x->P+index+1,sizeof(BTNode*)*(x->n-index));
            if(split.empty()) {x->P[index+1] = NULL;}
            else {x->P[index+1] = split.top(); split.pop();}
            x->n++;
            break;
        }
        else// make tempNode and  split it
        {
            BTNode * tempNode = getBTNode(m+1);
            BTNode *y = getBTNode(m);
            memcpy(tempNode->K,x->K,sizeof(int)*index);
            tempNode->K[index] = newKey;
            memcpy(tempNode->K+index+1,x->K+index, sizeof(int)*(m-1-index));
            if(x->P[0]!=NULL)
            {
                memcpy(tempNode->P,x->P,sizeof(BTNode*)*(index+1));
                tempNode->P[index+1] = split.top();
                split.pop();
                if(m>index) memcpy(tempNode->P+index+2,x->P+index+1, sizeof(BTNode*)*(m-index));
            }
            int mid = m/2;
            newKey =  tempNode->K[mid];
            //make x
            x->n = 0;
            for(int i=0;i<mid;i++)
            {
                x->K[i] = tempNode->K[i];
                x->P[i] = tempNode->P[i];
                x->n++;
            }
            x->P[mid] =tempNode->P[mid];
            //make y
            y->n = 0;
            for(int i=mid+1;i<m;i++)
            {
                y->K[i-mid-1] = tempNode->K[i];
                y->P[i-mid-1] = tempNode->P[i];

                x->K[i] = 0;
                x->P[i] = NULL;
                y->n++;
            }
            y->P[y->n] = tempNode->P[m];
            split.push(y);
            if(path.empty())
            {
                (*T) = getBTNode(m);
                (*T) ->K[0] = newKey;
                (*T) ->P[0] = x;
                (*T) ->P[1] = y;
                (*T) -> n = 1;
            }
        }
    }while(!path.empty());//end while
}//end insert

bool find_Sibling(BTNode * node , int index, int m)
{
    bool result = false;
    if(node ->n == index )
    {
        if(node->P[index-1]->n > m/2)
        {
            index--;
            result = true;
        }
    }
    else if(index == 0)
    {
        if(node->P[index+1]->n >m/2)
        {
            index++;
            result =  true;
        }
    }
    else
    {
        if(node->P[index-1]->n > m/2)
        {
            index--;
            result = true;
        }
        if(node->P[index+1]->n >m/2)
        {
            index++;
            result = true;
        }
    }
    return result;
}
/**
 * deleteBT deletes oldKey from T.
 * @param T: a B-tree
 * @param m: number of branch points in B-tree
 * @param oldKey: a key to delete
 */
void deleteBT(BTree *T, int m, int oldKey) {
    BTNode * x = *T;
    stack<BTNode*> path;

    int index;
    while( x != NULL)
    {
        index = 0;
        while( index< x->n && oldKey > x->K[index])
            index++;
        if(index <x->n && oldKey == x->K[index]) break;
        path.push(x);
        x = x->P[index];
    }
    if(x == NULL) return;

    BTNode * internalNode;
    int temp;
    if(x->P[0] != NULL)
    {
        internalNode = x;
        path.push(x);
        x = x->P[index];
        while(x->P[0] != NULL)
        {
            path.push(x);
            x = x->P[0];
        }
    }
    if(x == NULL)//exchange
    {
        x = path.top();
        path.pop();
        temp =internalNode->K[index];
        internalNode->K[index] =  x->K[x->n-1];
        x->K[1] = temp;
    }
    BTNode * y;
    if(!path.empty())
    {
        y = path.top();
        path.pop();
    }
    while(!path.empty())
    {
        if( x->n >m/2 )
        {
            for(int i=0;i<x->n;i++)
            {
                if(x->K[i] == oldKey)
                {
                    x->K[i] = 0;
                    x->n--;
                }
            }
            sort(x->K,x->K+x->n);
            break;
        }
        else if(find_Sibling(y,index,m))
        {
            int temp = y->K[index-1];
            int sib;
            if(y ->n == index )
            {
                if(y->P[index-1]->n > m/2)
                {
                    sib = index-1;
                }
            }
            else if(index == 0)
            {
                if(y->P[index+1]->n >m/2)
                {
                    sib = index+1;
                }
            }
            else
            {
                if(y->P[index-1]->n > m/2)
                {
                    sib = index-1;
                }
                if(y->P[index+1]->n >m/2)
                {
                    sib = index+1;
                }
            }
            BTNode* sibling = y->P[sib];
            y->K[index-1] = sibling->K[sibling->n-1];
            sibling->K[sibling->n-1] = 0;
            sibling->n--;
            x->K[x->n] = temp;
            for(int i=0;i<x->n;i++)
            {
                if(x->K[i] == oldKey)
                {
                    x->K[i] = 0;
                    x->n--;
                }
            }
            sort(x->K,x->K+x->n);
            break;
        }
        else
        {
            break;
        }
    }
    if(y->n == 0)
    {
        (*T) = x;
        delete y;
    }
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
