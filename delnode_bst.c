#include<stdio.h>
#include<stdlib.h>
struct listnode
{
    int data;
    struct listnode* link;
}*start=NULL;

struct treenode
{
    int data;
    struct treenode* lchild;
    struct treenode* rchild;
};
struct listnode* addtoempty(struct listnode *start,int data)
{
    struct listnode*temp=(struct listnode*)malloc(sizeof(struct listnode));
    temp->data=data;
    temp->link=NULL;
    start=temp;
    return start;
    printf("\n");
}
void addtoend(struct listnode *start,int data)
{
    struct listnode*p=start;
    while(p->link!=NULL)
    p=p->link;
     struct listnode*temp=(struct listnode*)malloc(sizeof(struct listnode));
    temp->data=data;
    temp->link=NULL;
    p->link=temp;
    printf("\n");
}
struct listnode* createlist(struct listnode*start,int n)
{
    if(n==0)
    {
        printf("list is empty\n");
        return start;
    }
    int i;
    int data;

    printf("enter data \n");
    scanf(" %d",&data);
    start=addtoempty(start,data);

    for(i=2;i<=n;i++)
    {
        printf("enter data \n");
        scanf(" %d",&data);
        addtoend(start,data);
    }
    return start;
    printf("\n");
}
void print(struct listnode*start)
{
    struct listnode*p=start;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
}
struct treenode* insert(struct treenode*ptr,int key)
{
    if(ptr==NULL)
    {
        struct treenode * ptr=(struct treenode*)malloc(sizeof(struct treenode));
        ptr->data=key;
       ptr->lchild=NULL;
        ptr->rchild=NULL;
        return ptr;
    }
    else if(key<ptr->data)
    ptr->lchild=insert(ptr->lchild,key);
    else if (key>ptr->data)
    ptr->rchild=insert(ptr->rchild,key);
    else
    printf("\n duplicate key\n");
    
    return ptr;
}
void inorder(struct treenode *p)
{
    if(p==NULL)
    return ;
    inorder(p->lchild);
    printf("%d ",p->data);
    inorder(p->rchild);
}
int main()
{
     int n;
    printf("enter number of element in list\n");
    scanf("%d",&n);

    struct listnode *start=NULL;
    start=createlist(start,n);
    printf("list is\n");
    print(start);

    struct treenode* root=NULL;
    struct listnode *pre=start;
    while(pre!=NULL)
    {
        root=insert(root,pre->data);
        pre=pre->link;
    } 
    printf("\ntree traversal inorder  is\n");
    inorder(root);

    int key;
    printf("\nenter key to delete\n");
    scanf("%d",&key);
    root=del(root,key);
}

