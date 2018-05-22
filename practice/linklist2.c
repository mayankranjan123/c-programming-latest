#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*start=NULL;
struct node*create(int data)
{
struct node*n=(struct node*)malloc(sizeof(struct node));
n->data=data;
n->next=NULL;
return n ;
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
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    }
}

int length()
{
    struct node*t=start;
    int count=1;
    if(start==NULL)
       return 0;
    else
    {
    while(t->next!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
    }
}

void detectLoop()
{
    struct node*t=start,*i,*j;
    i=j=start;
    while(i!=j)
    {
        i=i->next;
        j=j->next->next;
    }
    while(t!=i)
    {
        t=t->next;
        i=i->next;
    }
    printf("%d",t->data);

}

int main()
{
    struct node*c=start,*p,*q,*r,*s,*i,*o;
int n;
struct node*t=create(5);
start=t;
t->next=create(6);
t->next->next=create(7);
o=t->next->next;
t->next->next->next=create(1);
t->next->next->next->next=create(8);
//t->next->next->next->next->next=o;

display();
detectLoop();

}
