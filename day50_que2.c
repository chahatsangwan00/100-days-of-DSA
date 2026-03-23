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

struct TreeNode* searchNode(struct TreeNode* root, int target) {
    if (root == NULL || root->value == target) {
        return root;
    }

    if (target < root->value) {
        return searchNode(root->leftChild, target);
    } else {
        return searchNode(root->rightChild, target);
    }
}

void levelOrderPrint(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]");
        return;
    }

    struct TreeNode* queue[5000];
    int frontIndex = 0;
    int rearIndex = 0;

    queue[rearIndex++] = root;

    printf("[");

    while (frontIndex < rearIndex) {
        struct TreeNode* currentNode = queue[frontIndex++];

        if (currentNode == NULL) {
            printf("null");
        } else {
            printf("%d", currentNode->value);
            queue[rearIndex++] = currentNode->leftChild;
            queue[rearIndex++] = currentNode->rightChild;
        }

        if (frontIndex < rearIndex) {
            printf(",");
        }
    }

    printf("]");
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[5000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    struct TreeNode* root = buildTreeFromArray(arr, n, 0);

    struct TreeNode* result = searchNode(root, target);

    levelOrderPrint(result);

    return 0;
}