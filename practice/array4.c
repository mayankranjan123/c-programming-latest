#include<stdio.h>
int main()
{
    int i,j,a[]={3,2,5,4,6},sum=9;
    for(i=0;i<5;i++)
    {
    for(j=i+1;j<5;j++)
    {
        if(a[i]+a[j]==sum)
            printf("%d and %d\n",a[i],a[j]);
    }

    }
}
