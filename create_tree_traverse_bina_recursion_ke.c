#include<stdio.h>
#include<stdlib.h>

#define MAX 15
struct treenode *stack[MAX];
int top=-1;
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

void push(struct treenode*ptr)
{
    if(top==MAX-1)
    {
        printf("\n stack is overflow\n");
        exit(1);
    }
    top+=1;
    stack[top]=ptr;
}
struct treenode *pop()
{
    struct treenode *item;
    if(top==-1)
    {
        printf("\n stack is underflow\n");
        exit(1);
    }
    item=stack[top];
    top-=1;
    return item;
}
void nonrecursive_preorder_traverse(struct treenode *ptr)
{
    if(ptr==NULL)
    {
        printf("\n tree is empty\n");
        return;
    }
    //nhi to push kro
    push(ptr);
    while(top!=-1)
    {
        ptr=pop();
        printf("%c ",ptr->data);
        if(ptr->rchild!=NULL)
        push(ptr->rchild);
        if(ptr->lchild!=NULL)
        push(ptr->lchild);
    }
}

void nonrecursive_inorder_traverse(struct treenode *ptr)
{
    if(ptr==NULL)
    {
        printf("\n tree is empty\n");
        return;
    } 
    while(1)
    {
        while(ptr->lchild!=NULL)
        {
            push(ptr);
            ptr=ptr->lchild;
        }
        while(ptr->rchild==NULL)
        {
            printf("%c ",ptr->data);
            if(top==-1)
            return;
            ptr=pop();
        }
         printf("%c ",ptr->data);
         ptr=ptr->rchild;
    }
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

    printf("\npreorder traversal treeis\n");
    nonrecursive_preorder_traverse(root);
    printf("\n");
    printf("\ninorder traversal treeis\n");
    nonrecursive_inorder_traverse(root);
}

