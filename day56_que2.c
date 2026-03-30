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

struct Node* buildTree(int arr[], int n)
{
    if(n == 0) return NULL;

    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(nodes[i] != NULL)
        {
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n)
                nodes[i]->left = nodes[l];

            if(r < n)
                nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

int check(struct Node* a, struct Node* b)
{
    if(a == NULL && b == NULL)
        return 1;

    if(a == NULL || b == NULL)
        return 0;

    if(a->data != b->data)
        return 0;

    return check(a->left, b->right) && check(a->right, b->left);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if(check(root, root))
        printf("true");
    else
        printf("false");

    return 0;
}