#include<stdio.h>
void restoreup(int arr[],int i)
{
    int k=arr[i];
    int par=i/2;
    while(par>=1 && arr[par]<k)
    {
        arr[i]=arr[par];
        i=par;
        par=i/2;
    }
    arr[i]=k;
}
void buildheap(int arr[],int size)
{
    int i;
    for(i=2;i<=size;i++)
    restoreup(arr,i);
}
void display(int arr[],int size)
{
    if(size==0)
    {
        printf("empty heap\n");
        return;
    }
    int i;
    for(i=1;i<=size;i++)
    printf("%d ",arr[i]);
    printf("\n");
    printf(" size of heap is %d\n",size);
}
int main()
{
    int arr[20],size;
    printf("enter size\n");
    scanf("%d",&size);
    printf("enter elements\n");
    int i;
    for(i=1;i<=size;i++)
    scanf("%d",&arr[i]);
    buildheap(arr,size);  

    printf("\n heap is\n");
    display(arr,size);     
}