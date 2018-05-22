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
void intersection(struct node*t,struct node*p)
{
    int m,n,total,i;
    m=length(t);
    n=length(p);
    if(m>n)
    {

        total=m-n;

        for(i=0;i<total;i++)
        {
            t=t->next;
        }

    }
    else
    {
        total=n-m;
          for(i=0;i<total;i++)
        {
            p=p->next;
        }
    }
   //  printf("%d%d",t->data,p->data);
    while(t->data!=p->data)
    {


        t=t->next;
        p=p->next;
    }
    printf("Intersection is at:%d",t->data);

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
     start2->next->next->next=start1->next->next->next->next;
     intersection(start1,start2);
}

