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

struct TreeNode* insertIntoBST(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->leftChild = insertIntoBST(root->leftChild, value);
    } else {
        root->rightChild = insertIntoBST(root->rightChild, value);
    }

    return root;
}

struct TreeNode* findLCA(struct TreeNode* root, int firstValue, int secondValue) {
    if (root == NULL) {
        return NULL;
    }

    if (firstValue < root->value && secondValue < root->value) {
        return findLCA(root->leftChild, firstValue, secondValue);
    }

    if (firstValue > root->value && secondValue > root->value) {
        return findLCA(root->rightChild, firstValue, secondValue);
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        root = insertIntoBST(root, value);
    }

    int firstValue, secondValue;
    scanf("%d %d", &firstValue, &secondValue);

    struct TreeNode* lcaNode = findLCA(root, firstValue, secondValue);

    if (lcaNode != NULL) {
        printf("%d", lcaNode->value);
    }

    return 0;
}