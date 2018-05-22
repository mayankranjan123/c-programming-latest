#include<stdio.h>
#include<string.h>
int main()
{
    int f,i,n,j,count;
    char s[10];
    printf("Enter a string\n");
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        count=0;
        for(j=0;j<strlen(s);j++)
        {
            if(s[i]==s[j] && i!=j)
            {
                count=1;
                break;
            }


        }
         if(count==0)
         {
                printf("%c",s[i]);
         break;
         }

    }
    if(count==1)
        printf("No repeated characters\n");
}
