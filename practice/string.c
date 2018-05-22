#include<stdio.h>
#include<string.h>
int main()
{
    char s[10],t[10],count=0;
    printf("Enter 2 string\n");
    gets(s);
    gets(t);
    int i,j,n;
    n=strlen(s);
    if(n!=strlen(t))
    {
        printf("Not anagrams\n");
    }
    else
    {

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {

        if(s[i]==t[j])
        {
            count++;
            break;
        }

        }

    }
    if(count==n)
        printf("Anagrams\n");
    else
        printf("Not anagrams %d\n",count);

    }
}
