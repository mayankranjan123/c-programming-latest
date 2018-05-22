#include<stdio.h>
#include<stdlib.h>
int lis(int a[],int n)
{
    int *lis;
    lis=malloc(n*sizeof(int));
    int i,j,max=0;
    for(i=0;i<n;i++)
        lis[i]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(lis[i]>max)
        {
            max=lis[i];
        }
    }
    free(lis);
    return max;
}
int main()
{
    int a[]={1,3,4,7,5,8,9};
    int n;
    n=sizeof(a)/sizeof(a[0]);
   printf("%d",lis(a,n));
}
