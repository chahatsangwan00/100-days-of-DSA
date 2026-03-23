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

struct Queue {
    struct TreeNode* data[2000];
    int frontIndex;
    int rearIndex;
};

void initializeQueue(struct Queue* queue) {
    queue->frontIndex = 0;
    queue->rearIndex = 0;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->frontIndex == queue->rearIndex;
}

void enqueue(struct Queue* queue, struct TreeNode* node) {
    queue->data[queue->rearIndex++] = node;
}

struct TreeNode* dequeue(struct Queue* queue) {
    return queue->data[queue->frontIndex++];
}

void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]");
        return;
    }

    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, root);

    printf("[");

    while (!isQueueEmpty(&queue)) {
        int levelSize = queue.rearIndex - queue.frontIndex;
        printf("[");

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* currentNode = dequeue(&queue);
            printf("%d", currentNode->value);

            if (i < levelSize - 1) {
                printf(",");
            }

            if (currentNode->leftChild != NULL) {
                enqueue(&queue, currentNode->leftChild);
            }

            if (currentNode->rightChild != NULL) {
                enqueue(&queue, currentNode->rightChild);
            }
        }

        printf("]");

        if (!isQueueEmpty(&queue)) {
            printf(",");
        }
    }

    printf("]");
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("[]");
        return 0;
    }

    int arr[2000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTreeFromArray(arr, n, 0);
    levelOrder(root);

    return 0;
}