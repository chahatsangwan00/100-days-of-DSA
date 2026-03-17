#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    if(arr[0] == -1){
        printf("0");
        return 0;
    }

    struct node* nodes[n];

    for(int i = 0; i < n; i++){
        if(arr[i] != -1){
            nodes[i] = createNode(arr[i]);
        } else {
            nodes[i] = NULL;
        }
    }

    for(int i = 0; i < n; i++){
        if(nodes[i] != NULL){
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if(leftIndex < n){
                nodes[i]->left = nodes[leftIndex];
            }
            if(rightIndex < n){
                nodes[i]->right = nodes[rightIndex];
            }
        }
    }

    int h = height(nodes[0]);
    printf("%d", h);

    return 0;
}