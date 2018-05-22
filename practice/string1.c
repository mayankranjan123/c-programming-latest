#include<stdio.h>
#include<string.h>
void reverse(char*s)
{
    int i=0,n;
    n=strlen(s)-1;
    while(i<n)
    {
        s[i]=s[i]^s[n];
        s[n]=s[n]^s[i];
        s[i]=s[i]^s[n];
        i++;
        n--;
    }
    puts(s);
}
int main()
{
char s[10];
printf("Enter string\n");
gets(s);
reverse(s);
}
