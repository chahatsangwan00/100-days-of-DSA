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

struct Queue {
    struct TreeNode* data[1000];
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

void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, root);

    while (!isQueueEmpty(&queue)) {
        struct TreeNode* currentNode = dequeue(&queue);
        printf("%d ", currentNode->value);

        if (currentNode->leftChild != NULL) {
            enqueue(&queue, currentNode->leftChild);
        }

        if (currentNode->rightChild != NULL) {
            enqueue(&queue, currentNode->rightChild);
        }
    }
}

int main() {
    struct TreeNode* root = buildTree();
    levelOrderTraversal(root);
    return 0;
}