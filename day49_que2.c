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

struct TreeNode* insertValue(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->leftChild = insertValue(root->leftChild, value);
    } else {
        root->rightChild = insertValue(root->rightChild, value);
    }

    return root;
}

void levelOrderPrint(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]");
        return;
    }

    struct TreeNode* queue[10000];
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

    int arr[10000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int valueToInsert;
    scanf("%d", &valueToInsert);

    struct TreeNode* root = buildTreeFromArray(arr, n, 0);

    root = insertValue(root, valueToInsert);

    levelOrderPrint(root);

    return 0;
}