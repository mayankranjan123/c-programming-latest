#include<stdio.h>
#include<string.h>

int removee(char*s)
{
    if(!s || !*s)
    {
        return 0;
    }
    int count[256]={0},current=0,next=0;
    while(s[current]!='\0')
    {

        if(++count[s[current]]==1)
        {
            s[next]=s[current];

            next++;
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
    removee(s);
    puts(s);
    return 0;

}
