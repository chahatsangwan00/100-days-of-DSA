#include <stdio.h>
int main()
{
    int n;             
    int pos;            
    int x;              
  
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n + 1];     
   
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter position (1-based index): ");
    scanf("%d", &pos);
    
    printf("Enter element to insert: ");
    scanf("%d", &x);

    if(pos < 1 || pos > n + 1)
    {
        printf("Invalid position!\n");
        return 0;
    }

    for(int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
   
    arr[pos - 1] = x;
   
    printf("Updated array:\n");
    for(int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}