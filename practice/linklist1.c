#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*start=NULL;
struct node*create()
{
struct node*n=(struct node*)malloc(sizeof(struct node));
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
    start=t;
    else
    {
        t->next=start;
        start=t;
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
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
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
void reverse()
{
    struct node*current,*next,*prev=NULL,*t;
    t=current=next=start;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    start=prev;
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
int middle()
{
struct node*t=start,*p=start;
int n;
n=length();
if(n%2==0)
{
while(t!=NULL)
{
     p=p->next;
    t=t->next->next;

}
printf("%d",p->data);
}
else
{
    while(t->next!=NULL)
    {
        p=p->next;t=t->next->next;
    }
    printf("%d",p->data);
}
}
void rotate()
{
    struct node*t,*p,*k=start;
    int n;
    printf("Enter node to rotate about\n");
    scanf("%d",&n);
    t=start;
    while(t->data!=n)
    {
        t=t->next;
    }
    p=t->next;
    k=p;

    while(p->next!=NULL)
    {
        p=p->next;
    }
     p->next=start;
     start=k;
    t->next=NULL;

}
void sort()
{
    struct node*t=start,*i,*j;
    int temp;
for(i=start;i->next!=NULL;i=i->next)
{
    for(j=i->next;j!=NULL;j=j->next)
    {
        if(j->data<i->data)
        {
            temp=i->data;
            i->data=j->data;
            j->data=temp;
        }
    }

}
}
void removeduplicates()
{
    struct node*t=start,*p,*q;
    int a[10]={0};
    int i,j;
    q=t;
    while(t!=NULL)
    {
        if(a[t->data]==1)
        {
            p=t->next;
            q->next=p;
            free(t);
            t=q->next;
        }
        else
        {
            a[t->data]=1;
        }
        q=t;
        t=t->next;
    }


}
struct node* adjacentSwap()
{

    struct node*t=start;
 int temp;
    struct node*p=start,*q,*store,*ns;
    ns=p->next;
    while(1)
    {
        q=p->next;
        store=q->next;
        q->next=p;
        if(store==NULL || store->next==NULL)
        {
            p->next=store;
            break;
        }
        p->next=store->next;
        p=store;
    }
    return ns;


}
void detectLoop()
{
    struct node*t;
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
printf("4.Reverse linked list\n");
printf("5.Length of linked list\n");
printf("6.Find middle node\n");
printf("7.Rotate linked list\n");
printf("8.Sort elements\n");
printf("9.Remove duplicates\n");
printf("10.Adjacent Swap\n");
scanf("%d",&n);
switch(n)
{
    case 1:addBegin();
        break;
    case 2:display();
        break;
    case 3:addLast();
        break;
    case 4:reverse();
        break;
    case 5:length();
        break;
    case 6:middle();
        break;
    case 7:rotate();
        break;
    case 8:sort();
        break;
    case 9:removeduplicates();
        break;
    case 10:
        t=adjacentSwap();
        break;
}
}
}
