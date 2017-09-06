#include "opftree.h"


OPFTree *CreateOPFTree(int nnodes) {
    OPFTree* tree = (OPFTree *)malloc(sizeof(OPFTree));
    if (tree == NULL) {
        Error("Cannot allocate tree", "CreateOPFTree");
    }

    tree->nodes = (TNode *)calloc(nnodes, sizeof(OPFTree));
    if (tree->nodes) {
        Error("Cannot allocate nodes", "CreateOPFTree");
    }

    tree->_used_nodes = 0;
    tree->_capacity = nnodes;
}


void DestroyOPFTree(OPFTree **tree) {
    free((*tree)->nodes);
    free((*tree));
    *tree = NULL;
}


TNode *GetNewOPFTreeNode(OPFTree *tree) {
    if (tree->_used_nodes == tree->_capacity) {
        Error("No more available nodes", "GetNewOPFTreeNode");
    }
    return &tree->nodes[tree->_used_nodes++];
}
