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
struct treenode* createtree(struct listnode*in,struct listnode*post,int num)
{
    struct treenode *temp;
    struct listnode *q,*p;
    int i;
    if(num==0)
    return NULL;

    p=post;
    for(i=1;i<num;i++)
    p=p->link;

    temp=(struct treenode*)malloc(sizeof(struct treenode));
    temp->data=p->data;
    temp->lchild=NULL;
    temp->rchild=NULL;
    if(num==1)
    return temp;

    q=in;
    for(i=0;q->data!=p->data;i++)
    q=q->link;
    temp->lchild=createtree(in,post,i);

    int j;
    for(j=1;j<=i;j++)
    post=post->link;
    temp->rchild=createtree(q->link,post,num-i-1);
    return temp;
}
void postorder(struct treenode* p)
{
    if(p==NULL)
    return ;
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%c ",p->data);
}

void inorder(struct treenode *p)
{
    if(p==NULL)
    return ;
    inorder(p->lchild);
    printf("%c ",p->data);
    inorder(p->rchild);
}
void preorder(struct treenode *p)
{
    if(p==NULL)
    return ;
    printf("%c ",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
}
int main()
{
    struct listnode *post=NULL,*in=NULL;
    post=createlist(post);
    in=createlist(in);

    printf("postorder list is\n");
    print(post);
    printf("inorder list is\n");
    print(in);

    struct treenode* root=NULL;
    printf("\nhi1\n");
    root=createtree(in,post,11);
    printf("\nhi2\n");

    printf("tree traversal postorder is\n");
    postorder(root);
    printf("\ntree traversal inorder  is\n");
    inorder(root);
    printf("\ntree traversal pretorder is\n");
    preorder(root);
}

// postorder list is
// h i d j e b k f g c a 
// inorder list is
// h d i b e j a k f c g 

