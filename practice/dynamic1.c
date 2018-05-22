#include<stdio.h>
#include<string.h>
void sort(int s[],int f[],int n,int t[]);
void sort(int s[],int f[],int n,int t[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(f[i]<f[j])
            {
                f[i]=f[i]^f[j];
                f[j]=f[j]^f[i];
                f[i]=f[i]^f[j];

                s[i]=s[i]^s[j];
                s[j]=s[j]^s[i];
                s[i]=s[i]^s[j];

                t[i]=t[i]^t[j];
                t[j]=t[j]^t[i];
                t[i]=t[i]^t[j];
            }
        }
    }
 /*   for(i=0;i<n;i++)
    {
    printf("%d\t",s[i]);
    printf("%d\t",f[i]);
    printf("%d\t",t[i]);
    }
    */
}
void activity(int s[],int f[],int n,int t[])
{
int i=0,j;
printf("%d\t",t[i]);
for(j=1;j<n;j++)
{
    if(s[j]>=f[i])
    {
        printf("%d\t",t[j]);
        i=j;
    }
}
}
int main()
{
    int n,i;

printf("Enter total no. of activities\n");
scanf("%d",&n);
int s[n],f[n],t[n];
for(i=0;i<n;i++)
{
t[i]=i;
}
printf("Enter start and finish time in pair\n");
for(i=0;i<n;i++)
{
    scanf("%d%d",&s[i],&f[i]);
}
sort(s,f,n,t);
activity(s,f,n,t);
}
