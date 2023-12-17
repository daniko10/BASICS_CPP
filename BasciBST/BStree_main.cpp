#include "DEFINITIONS.h"

int main() {
    int TabNodes[] = {5,4,1,3,43,54,2,12,32,54,232,3212,435,235,12111,324,2344,2355,22,1,33};
    BinarySearchTree* root = NULL;

    for(int i=0; i<sizeof(TabNodes)/sizeof(int); i++)
        AddLeaf(&root, NULL, TabNodes[i]);

    PrintInOrder(root);
    DeleteTree(root);
}