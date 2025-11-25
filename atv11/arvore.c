#include "node.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    int arr[] = {123, 1, 123, 123, 1, 33, 44, 12, 99, 16};
    
    TreeNode* root = createNode(123);
    addNode(root, 1);
    addNode(root, 123);
    addNode(root, 123);
    addNode(root, 1);
    addNode(root, 33);
    addNode(root, 44);
    addNode(root, 12);
    addNode(root, 99);
    addNode(root, 16);

    preOrder(root);
}