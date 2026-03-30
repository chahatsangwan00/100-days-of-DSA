#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int hd;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->hd = 0;
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

struct Queue
{
    struct Node* node;
    int hd;
};

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    struct Queue q[1000];
    int front = 0, rear = 0;

    int min = 0, max = 0;

    int result[2000][100];
    int count[2000] = {0};

    if(root != NULL)
    {
        root->hd = 0;
        q[rear++] = (struct Queue){root, 0};
    }

    while(front < rear)
    {
        struct Queue temp = q[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        if(hd < min) min = hd;
        if(hd > max) max = hd;

        int index = hd + 1000;
        result[index][count[index]++] = curr->data;

        if(curr->left != NULL)
        {
            curr->left->hd = hd - 1;
            q[rear++] = (struct Queue){curr->left, hd - 1};
        }

        if(curr->right != NULL)
        {
            curr->right->hd = hd + 1;
            q[rear++] = (struct Queue){curr->right, hd + 1};
        }
    }

    for(int i = min; i <= max; i++)
    {
        int index = i + 1000;
        for(int j = 0; j < count[index]; j++)
        {
            printf("%d ", result[index][j]);
        }
        printf("\n");
    }

    return 0;
}