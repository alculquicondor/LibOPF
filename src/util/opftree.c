#include "opftree.h"


OPFTree *CreateOPFTree(int nnodes) {
    OPFTree* tree = (OPFTree *)malloc(sizeof(OPFTree));
    if (tree == NULL) {
        Error("Cannot allocate tree", "CreateOPFTree");
    }

    tree->nodes = (TNode *)calloc(nnodes, sizeof(TNode));
    if (tree->nodes == NULL) {
        Error("Cannot allocate nodes", "CreateOPFTree");
    }

    tree->nnodes = nnodes;
    return tree;
}


void DestroyOPFTree(OPFTree **tree) {
    free((*tree)->nodes);
    free((*tree));
    *tree = NULL;
}

void SwapTNode(TNode *a, TNode *b) {
    TNode tmp = *a;
    *a = *b;
    *b = tmp;
}
