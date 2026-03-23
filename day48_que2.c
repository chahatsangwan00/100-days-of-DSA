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

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    if (root->leftChild != NULL) {
        if (root->leftChild->leftChild == NULL && root->leftChild->rightChild == NULL) {
            sum += root->leftChild->value;
        } else {
            sum += sumOfLeftLeaves(root->leftChild);
        }
    }

    sum += sumOfLeftLeaves(root->rightChild);

    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTreeFromArray(arr, n, 0);

    int result = sumOfLeftLeaves(root);
    printf("%d", result);

    return 0;
}