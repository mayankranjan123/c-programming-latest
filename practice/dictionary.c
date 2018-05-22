#include<stdio.h>
int main()
{
    char str[6][10],s[10];
    int i,r,round;
    printf("Enter 6 string\n");
    for(i=0;i<6;i++)
    gets(str[i]);
    for(round=1;round<=5;round++)
    {
        for(i=0;i<=5-round;i++)
        {
            r=strcmp(str[i],str[i+1]);
            if(r>0)
            {
                strcpy(s,str[i]);
                strcpy(str[i],str[i+1]);
                strcpy(str[i+1],s);
            }
        }
    }
    for(i=0;i<6;i++)
    {
        puts(str[i]);
    }

}
