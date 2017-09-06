#ifndef _OPFTREE_H
#define _OPFTREE_H

#include "subgraph.h"

typedef struct _tnode {
    SNode *sgnode;
    float dcost;  // median cost
    struct _tnode *lchild;
    struct _tnode *rchild;
} TNode;


typedef struct _opftree {
    TNode *nodes;
    int nnodes;
} OPFTree;


/*------ Constructor and destructor ----------*/
OPFTree *CreateOPFTree(int nnodes);  // Allocates nodes for the tree
void DestroyOPFTree(OPFTree **tree);  // Deallocates memoery for opftree

void SwapTNode(TNode *a, TNode *b);  // Swap nodes

#endif //_OPFTREE_H
