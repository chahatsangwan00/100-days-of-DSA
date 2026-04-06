#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int cameras = 0;

int dfs(struct Node* root)
{
    if(root == NULL)
        return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if(left == -1 || right == -1)
    {
        cameras++;
        return 0;
    }

    if(left == 0 || right == 0)
        return 1;

    return -1;
}

int minCameraCover(struct Node* root)
{
    if(dfs(root) == -1)
        cameras++;
    return cameras;
}

struct Node* buildTree(int arr[], int n, int i)
{
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = newNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int result = minCameraCover(root);

    printf("%d", result);

    return 0;
}