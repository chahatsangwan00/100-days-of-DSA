#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inorder(struct node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d",&n);

    if(n==0)
        return 0;

    int arr[200];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct node* nodes[200];

    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1)
            nodes[i]=NULL;
        else
            nodes[i]=create(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(nodes[i]!=NULL)
        {
            int l=2*i+1;
            int r=2*i+2;

            if(l<n)
                nodes[i]->left=nodes[l];
            if(r<n)
                nodes[i]->right=nodes[r];
        }
    }

    inorder(nodes[0]);

    return 0;
}