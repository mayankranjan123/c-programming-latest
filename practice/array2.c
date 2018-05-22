#include<stdio.h>
#include<math.h>
int square(int n)
{
int k;
k=sqrt(n);
if((k*k)==n)
    return 1;
else
    return 0;

}
int isFibonnacci(int i)
{
    return(square(5*i*i+4) || square(5*i*i-4));
}
int main()
{
    int i,j,n;
    for(i=1;i<=10;i++)
    {
        isFibonnacci(i)? printf("%d is Fibonacci\n",i):
                        printf("%d is not Fibonacci\n",i);
    }
}
