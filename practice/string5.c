#include<stdio.h>
#include<string.h>
void removeSpaces(char s[],int n)
{
    int i,j,current=0,next=0;
    while(s[current]!='\0')
    {
if(s[current]!=' ')
{
s[next]=s[current];
next++;
}
current++;
    }
    s[next]='\0';
    strlwr(s);

}
int main()
{

    char s[]="My name is Mayank ";
    int n;
    n=strlen(s);
    removeSpaces(s,n);
    puts(s);
}
