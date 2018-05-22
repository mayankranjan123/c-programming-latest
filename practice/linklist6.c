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
int length(struct node*t)
{
    int count=0;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}
void merge(struct node*t,struct node*p)
{
struct node*next1,*curr1,*prev1,*next2,*curr2,*prev2;
curr1=t;
curr2=p;

while(t!=NULL && p!=NULL)
{
printf("%d%d",curr1->data,curr2->data);
    next1=curr1->next;
    next2=curr2->next;

    curr1->next=curr2;
    curr2->next=next1;
    curr2=next2;
    curr1=next1;

}


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
    struct node*start1,*start2;
    start1=create(1);
    start1->next=create(2);
    start1->next->next=create(3);
    start1->next->next->next=create(4);
    start1->next->next->next->next=create(8);
    start1->next->next->next->next->next=create(9);
    start2=create(5);
    start2->next=create(6);
    start2->next->next=create(7);
    merge(start1,start2);
    display(start1);
}
