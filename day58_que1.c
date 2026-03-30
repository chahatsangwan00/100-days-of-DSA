#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int search(int inorder[], int start, int end, int value)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* build(int preorder[], int inorder[], int start, int end, int* index)
{
    if(start > end)
        return NULL;

    struct Node* root = createNode(preorder[*index]);
    (*index)++;

    if(start == end)
        return root;

    int pos = search(inorder, start, end, root->data);

    root->left = build(preorder, inorder, start, pos - 1, index);
    root->right = build(preorder, inorder, pos + 1, end, index);

    return root;
}

void postorder(struct Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int index = 0;

    struct Node* root = build(preorder, inorder, 0, n - 1, &index);

    postorder(root);

    return 0;
}