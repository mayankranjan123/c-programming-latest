#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
}*start=NULL,*end=NULL;
struct node*create()
{
struct node*n=(struct node*)malloc(sizeof(struct node));
n->prev=NULL;
n->next=NULL;
return n ;
}
void addBegin()
{
    int n;
    printf("Enter data\n");
    scanf("%d",&n);
    struct node*t;
    t=create();
    t->data=n;
    if(start==NULL)
    {
    start=t;
    end=t;
    }
    else
    {
        t->prev=end;
        t->next=start;
        end->next=t;
        end=t;
    }
}
void display()
{
    struct node*t=start;
    if(start==NULL)
    {
        printf("No elements\n");
    }
    else
    {
    while(t->next!=start)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("%d\t",t->data);
    }
}
void addLast()
{
    struct node*t=start,*p;
    int n;
    printf("Enter data\n");
    scanf("%d",&n);
    p=create();
    p->data=n;
    if(start==NULL)
    start=p;
    else
    {
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=p;
    p->next=NULL;

    }
}


int main()
{
    struct node*t=start;
int n;
while(1)
{
printf("\n1.Enter at beginning\n");
printf("2.Display elements\n");
printf("3.Add element at last\n");
scanf("%d",&n);
switch(n)
{
    case 1:addBegin();
        break;
    case 2:display();
        break;
    case 3:addLast();
        break;

}
}
}
