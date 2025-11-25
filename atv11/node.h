#ifndef ARVORE_H
#define ARVORE_H

typedef struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right; 
} TreeNode;

TreeNode* createNode(int value);
TreeNode* addNode(TreeNode* root, int value);
void preOrder(TreeNode* root);

#endif