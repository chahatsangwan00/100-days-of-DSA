#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int value)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* build(int inorder[], int postorder[], int start, int end, int *index)
{
    if(start > end)
        return NULL;

    int value = postorder[*index];
    (*index)--;

    struct TreeNode* root = newNode(value);

    if(start == end)
        return root;

    int pos = findIndex(inorder, start, end, value);

    root->right = build(inorder, postorder, pos + 1, end, index);
    root->left = build(inorder, postorder, start, pos - 1, index);

    return root;
}

void printLevelOrder(struct TreeNode* root)
{
    if(root == NULL)
        return;

    struct TreeNode* queue[3000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear)
    {
        struct TreeNode* temp = queue[front++];

        if(temp == NULL)
        {
            printf("null ");
            continue;
        }

        printf("%d ", temp->val);

        queue[rear++] = temp->left;
        queue[rear++] = temp->right;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int index = n - 1;

    struct TreeNode* root = build(inorder, postorder, 0, n - 1, &index);

    printLevelOrder(root);

    return 0;
}