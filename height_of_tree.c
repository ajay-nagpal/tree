#include<stdio.h>
#include<stdlib.h>
struct listnode
{
    char data;
    struct listnode* link;
}*start=NULL;

struct treenode
{
    char data;
    struct treenode* lchild;
    struct treenode* rchild;
};
struct listnode* addtoempty(struct listnode *start,char data)
{
    struct listnode*temp=(struct listnode*)malloc(sizeof(struct listnode));
    temp->data=data;
    temp->link=NULL;
    start=temp;
    return start;
    printf("\n");
}
struct listnode* addtoend(struct listnode *start,char data)
{
    struct listnode*p=start;
    while(p->link!=NULL)
    p=p->link;
     struct listnode*temp=(struct listnode*)malloc(sizeof(struct listnode));
    temp->data=data;
    temp->link=NULL;
    p->link=temp;
    return start;
    printf("\n");
}
struct listnode* createlist(struct listnode*start)
{
    int n;
    printf("enter number of element in list\n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("list is empty\n");
        return start;
    }
    int i;
    char data;

    printf("enter data \n");
    scanf(" %c",&data);
    start=addtoempty(start,data);

    for(i=2;i<=n;i++)
    {
        printf("enter data \n");
        scanf(" %c",&data);
        start=addtoend(start,data);
    }
    return start;
    printf("\n");
}
void print(struct listnode*start)
{
    struct listnode*p=start;
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p=p->link;
    }
    printf("\n");
}
struct treenode* createtree(struct listnode*in,struct listnode*pre,int num)
{
    struct treenode *temp;
    struct listnode *q;
    if(num==0)
    return NULL;

    temp=(struct treenode*)malloc(sizeof(struct treenode));
    temp->data=pre->data;
    temp->lchild=NULL;
    temp->rchild=NULL;
    if(num==1)
    return temp;

    int i;
    q=in;
    for(i=0;q->data!=pre->data;i++)
    q=q->link;

    temp->lchild=createtree(in,pre->link,i);

    for(int j=1;j<=i+1;j++)
    pre=pre->link;
    temp->rchild=createtree(q->link,pre,num-i-1);
    return temp;
}
void preorder(struct treenode* p)
{
    if(p==NULL)
    return ;
    printf("%c ",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
}

void inorder(struct treenode *p)
{
    if(p==NULL)
    return ;
    inorder(p->lchild);
    printf("%c ",p->data);
    inorder(p->rchild);
}
int height(struct treenode *ptr)
{
     int height_left, height_right;
    if(ptr==NULL)
    {
        return 0;
    }
    height_left=height(ptr->lchild);
    height_right=height(ptr->rchild);
    if(height_left> height_right)
    return 1+ height_left;
    else
    return 1+ height_right;
}
int main()
{
    struct listnode *pre=NULL,*in=NULL;
    pre=createlist(pre);
    in=createlist(in);

    printf("preorder list is\n");
    print(pre);
    printf("inorder list is\n");
    print(in);

    struct treenode* root=NULL;
    root=createtree(in,pre,5);
    printf("tree traversal preorder is\n");
    preorder(root);
    printf("\ntree traversal inorder  is\n");
    inorder(root);

    int h=height(root);
    printf("\n height is %d",h);
}

