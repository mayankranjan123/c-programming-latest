#include<stdio.h>
#include<string.h>

int *create_array(int m)
{
    int *a=(int *)malloc(sizeof(int)*m);
    int i;
    for(i=0;i<m;i++)
    {
        a[i]=0;
    }
    return a;
}

int fail(char *p,int *f)
{
        int m;
    m=strlen(p);
int i,j;
    i=1;
    j=0;
    f[0]=0;
while(i<m)
{
if(p[i]==p[j])
{
f[i]=j+1;
i++;
j++;
}
else
{
if(j>0)
{
j=f[j-1];
}
else
{
    f[i]=0;
    i++;
}
}
}

}
int kmp(char *t,char *p)
{
    int m,n;
    m=strlen(p);
    n=strlen(t);
    int i=0,j=0;
    int *f=create_array(m);
    //fail(p,m);
        while(i<n)
    {
        if(p[j]==t[i])
        {
            if(j==m-1)
                return i-j;
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            if(j>0)
            {
                j=f[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return -1;
}
int main()
{
  char* pattern = "C";
  char* text = "Welcome To CampusCoke";

  int match = kmp(text, pattern);

  printf("Match at: %d\n", match);

  return 0;
}
