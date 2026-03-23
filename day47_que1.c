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

int findHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = findHeight(root->leftChild);
    int rightHeight = findHeight(root->rightChild);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int main() {
    struct TreeNode* root = buildTree();
    int height = findHeight(root);
    printf("%d", height);
    return 0;
}