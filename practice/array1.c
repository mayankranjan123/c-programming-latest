#include<stdio.h>

void linear_search(int a[],int n)
{
int i,f=0,item;
printf("Enter item to search\n");
scanf("%d",&item);
for(i=0;i<n;i++)
{
    if(a[i]==item)
    {
        printf("Match found at : %d position\n",i);
        f=1;
    }
    if(i==n-1 && f==0)
    {
        printf("Element not found\n");
    }
}
}
int binary_search(int a[],int lb,int ub,int item)
{
int mid;

if(lb<=ub)
{
    mid=(lb+ub)/2;
    if(a[mid]==item)
     return mid;
    else if(item<a[mid])
    binary_search(a,lb,mid-1,item);
    else
       binary_search(a,mid+1,ub,item);
}
else
   return -1;



}
void get_maxMin(int a[],int lb,int ub,int max,int min)
{
    int mid,max1,min1;
    if(lb==ub)
    {
        max=min=a[lb];

    }
    else if(lb==ub-1)
    {

        if(a[lb]>a[ub])
        {
            max=a[lb];
            min=a[ub];
        }
        else
        {
            max=a[ub];
            min=a[lb];
        }
    }
    else
    {
        mid=(lb+ub)/2;
        get_maxMin(a,lb,mid,max,min);
        get_maxMin(a,mid+1,ub,max1,min1);
        if(max1>max)
        {
            max=max1;
        }
        if(min1<min)
        {
            min=min1;
        }
        printf("Maximum and minimum is %d and %d",max1,min);

    }

}


int main()
{
    int a[]={1,2,4,5,7,9},item;
    int r,p;
    r=(sizeof(a)/sizeof(a[0]));

while(1)
{

    int n;
    printf("\nEnter choice\n");
    printf("1.Linear Search\n");
    printf("2.Binary Search\n");
    printf("3.Find max-min\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:linear_search(a,sizeof(a)/sizeof(a[0]));
                break;
        case 2:
            printf("Enter item to search\n");
            scanf("%d",&item);
            p=binary_search(a,0,r-1,item);
            if(p==-1)
                printf("Element not found\n");
            else
            {
                printf("Element found at %d\n",p);
            }

                break;
        case 3:get_maxMin(a,0,r-1,a[0],a[0]);
                break;
    }

}

}
