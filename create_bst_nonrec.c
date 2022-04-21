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
struct treenode* insert(struct treenode*root,int key)
{
    struct treenode *ptr=root;
    struct treenode *par=NULL;
    while(ptr!=NULL)
    {
        par=ptr;
        if(key<ptr->data)
        ptr=ptr->lchild;
        else if(key>ptr->data)
        ptr=ptr->rchild;
        else
        {
            printf("\n duplicate key\n");
            return root;
        }
    }
    struct treenode *temp=(struct treenode*)malloc(sizeof(struct treenode));
    temp->data=key;
    temp->lchild=NULL;
    temp->rchild=NULL;

    if(par==NULL)
    root=temp;
    else if(key<par->data)
    par->lchild=temp;
    else
    par->rchild=temp;
    return root;
}
int preorder(struct treenode* p)
{
    if(p==NULL)
    return 0;
    printf("%d ",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
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
}

