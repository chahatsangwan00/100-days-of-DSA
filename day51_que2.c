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

struct TreeNode* buildTreeFromArray(int arr[], int size, int index) {
    if (index >= size || arr[index] == -1001) {
        return NULL;
    }

    struct TreeNode* root = createNode(arr[index]);
    root->leftChild = buildTreeFromArray(arr, size, 2 * index + 1);
    root->rightChild = buildTreeFromArray(arr, size, 2 * index + 2);

    return root;
}

struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }

    if (p < root->value && q < root->value) {
        return findLCA(root->leftChild, p, q);
    }

    if (p > root->value && q > root->value) {
        return findLCA(root->rightChild, p, q);
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* root = buildTreeFromArray(arr, n, 0);

    struct TreeNode* lcaNode = findLCA(root, p, q);

    if (lcaNode != NULL) {
        printf("%d", lcaNode->value);
    }

    return 0;
}