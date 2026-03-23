#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

struct TreeNode* buildTree() {
    int value;
    scanf("%d", &value);

    if (value == -1) {
        return NULL;
    }

    struct TreeNode* root = createNode(value);
    root->leftChild = buildTree();
    root->rightChild = buildTree();

    return root;
}

int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->leftChild == NULL && root->rightChild == NULL) {
        return 1;
    }

    int leftCount = countLeafNodes(root->leftChild);
    int rightCount = countLeafNodes(root->rightChild);

    return leftCount + rightCount;
}

int main() {
    struct TreeNode* root = buildTree();
    int leafCount = countLeafNodes(root);
    printf("%d", leafCount);
    return 0;
}