#include<stdio.h>
int main()
{
    int n,f=0,i,j;
    printf("Enter a number\n");
    scanf("%d",&n);
    j=n/2;

    for(i=2;i<=n/2;++i)
    {
        if(n%i == 0)
        {
           f++;
           break;
        }
    }
    if(f!=0)
        printf("%d is a prime number\n",n);
    if(f==0)
        printf("%d is not a prime number\n",n);
}
