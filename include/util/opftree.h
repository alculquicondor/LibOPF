#ifndef _OPFTREE_H
#define _OPFTREE_H

#include "subgraph.h"

typedef struct _tnode {
    SNode *sgnode;
    float median;
    struct _tnode *lchild;
    struct _tnode *rchild;
} TNode;


typedef struct _opftree {
    TNode *nodes;
    int _used_nodes;
    int _capacity;
} OPFTree;


/*------ Constructor and destructor ----------*/
OPFTree *CreateOPFTree(int nnodes);  // Allocates nodes for the tree
void DestroyOPFTree(OPFTree **tree);  // Deallocates memoery for opftree

TNode *GetNewOPFTreeNode(OPFTree *tree);  // Gets a new node from allocated nodes

#endif //_OPFTREE_H
