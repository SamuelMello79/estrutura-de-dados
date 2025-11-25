#include "node.h"
#include <stdlib.h>
#include <stdio.h>

TreeNode* createNode(int value) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* addNode(TreeNode* root, int value) {
    if (root == NULL) createNode(root);
    if (value < root->value) {
        root->left = addNode(root->left, value);
    } else {
        root->right = addNode(root->right, value);
    }
    return root;
}

void preOrder(TreeNode* root) {
    if (root != NULL) {
        preOrder(root->left);
        printf("%d ", root->value);
        preOrder(root->right);
    }
}