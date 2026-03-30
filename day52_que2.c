#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
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
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

struct Node* LCA(struct Node* root, int p, int q)
{
    if(root == NULL)
        return NULL;

    if(root->val == p || root->val == q)
        return root;

    struct Node* left = LCA(root->left, p, q);
    struct Node* right = LCA(root->right, p, q);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;

    return right;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, n);

    struct Node* ans = LCA(root, p, q);

    if(ans != NULL)
        printf("%d", ans->val);

    return 0;
}