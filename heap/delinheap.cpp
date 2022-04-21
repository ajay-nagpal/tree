#include<stdio.h>
void restoredown(int arr[],int i,int size)
{
    int lchild=2*i,rchild=lchild+1;
    int num=arr[i];
    while(rchild<=size)
    {
        if(num>arr[lchild] && num>arr[rchild])
        {
            arr[i]=num;
            return;
        }
        if(arr[lchild]>arr[rchild])
        {
            arr[i]=arr[lchild];
            i=lchild;
        }
        else
        {
            arr[i]=arr[rchild];
            i=rchild;
        }
        lchild=2*i;
        rchild=lchild+1;      
    }
    if(lchild==size && num<arr[lchild])
    {
        arr[i]=arr[lchild];
        i=lchild;
    }
    arr[i]=num;
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
}
void buildheap(int arr[],int size)
{
    int i;
    for(i=size/2;i>=1;i--)
    restoredown(arr,i,size);
}
int  del(int arr[],int *size)
{
    int max=arr[1];
    arr[1]=arr[*size];
    (*size)--;
    restoredown(arr,1,*size);
    return max;
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

    printf(" \nsize of heap is %d\n",size);

    int num;
   

    num=del(arr,&size);
     printf("\n now heap is\n");
    display(arr,size);
     printf(" \nsize of heap is %d\n",size);
     printf(" \ndel el is %d\n",num);
}