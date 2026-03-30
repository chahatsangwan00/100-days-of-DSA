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

void flatten(struct Node* root)
{
    if(root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    if(root->left != NULL)
    {
        struct Node* temp = root->left;

        while(temp->right != NULL)
            temp = temp->right;

        temp->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
}

void printList(struct Node* root)
{
    struct Node* curr = root;

    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    if(n == 0)
        return 0;

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    flatten(root);

    printList(root);

    return 0;
}