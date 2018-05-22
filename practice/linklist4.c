#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*create(int data)
{
    struct node*n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;
    return n;
}
void detectLoop(struct node*t)
{
    struct node*p,*r;
    r=p=t;
    while(t!=NULL && t->next!=NULL && p!=NULL)
    {
         t=t->next->next;
        p=p->next;
        if(t->data==p->data)
        {
           findLoopNode(t,r);
           break;
        }

    }
}
void findLoopNode(struct node*t,struct node*r)
{
   struct node*prev=r;
    while(r->data!=t->data)
    {
        prev=t;
        r=r->next;
        t=t->next;
    }
    printf("%d\n",t->data);
    prev->next=NULL;
    //printf("%d",prev->data);
}
void display(struct node*t)
{
while(t!=NULL)
{
    printf("%d\t",t->data);
    t=t->next;
}
}
int main()
{
struct node*t;
t=create(5);
t->next=create(7);
t->next->next=create(9);
t->next->next->next=create(12);
t->next->next->next->next=create(14);
t->next->next->next->next->next=create(18);
t->next->next->next->next->next->next=create(19);
t->next->next->next->next->next->next->next=t->next->next;
detectLoop(t);
display(t);

}
