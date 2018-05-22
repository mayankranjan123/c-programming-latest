#include<stdio.h>
#include<string.h>
int isSubset(int a[],int sum,int n)
{
    if(sum==0)
        return 1;
    if(n==0 && sum!=0)
        return 0;

if(a[n-1]>sum)
    return(a,sum,n-1);

    return isSubset(a,sum,n-1) || isSubset(a,sum-a[n-1],n-1);
}
int main()
{
  int set[] = {1,2,4,6,5};
  int sum = 3;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubset(set, sum, n) == 1)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}
