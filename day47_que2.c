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
    if (index >= size || arr[index] == -101) {
        return NULL;
    }

    struct TreeNode* root = createNode(arr[index]);
    root->leftChild = buildTreeFromArray(arr, size, 2 * index + 1);
    root->rightChild = buildTreeFromArray(arr, size, 2 * index + 2);

    return root;
}

int findMaxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = findMaxDepth(root->leftChild);
    int rightDepth = findMaxDepth(root->rightChild);

    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    int arr[10000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTreeFromArray(arr, n, 0);

    int depth = findMaxDepth(root);
    printf("%d", depth);

    return 0;
}