#include<stdio.h>
#include<string.h>
//repeated characters
int repeat(char *s)
{
if(!s || !*s)
    return 0;
int count[256]={0},current=0,next=0;
int i=0,n;
n=strlen(s);
while(s[current]!='\0')
{
    if(++count[s[current]]==2)
    {
        s[next++]=s[current];
    }
current++;
}
s[next]='\0';
return next;
}

int main()
{
    char s[10];
    printf("Enter a string\n");
    gets(s);
    repeat(s);
    puts(s);


}
