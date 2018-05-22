#include<stdio.h>
#include<stdlib.h>
int mai[4][4];
int state[20];
int queue[20];
int visited[10],pt=0;
int f=-1,r=-1;
struct Graph
{
    int V,E;
    int *Adj;
};
struct Graph*create()
{
    struct Graph*g;
    int i,u,v;
    g=(struct Graph*)malloc(sizeof(struct Graph));
    printf("Enter no. of nodes and edges\n");
    scanf("%d%d",&g->V,&g->E);
    g->Adj=malloc((g->V)*(g->V)*sizeof(int));
    for(u=0;u<g->V;u++)
    {
        for(v=0;v<g->V;v++)
        {
            *(g->Adj+u*g->V+v)=0;
        }
    }
    printf("Enter nodes in pair \n");
    for(i=0;i<g->E;i++)
    {
    scanf("%d%d",&u,&v);
    *(g->Adj+u*g->V+v)=1;
    *(g->Adj+v*g->V+u)=1;

    }
    return g;

}
void printSolution(struct Graph*g)
{
   int i,j;
    for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
            printf("%7d",*(g->Adj+i*g->V+j));
        }
        printf("\n");
    }
}
void printPath(struct Graph*g)
{
    int i,j;
    for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
            if(*(g->Adj+i*g->V+j)==1)
            {
                printf("\tPath is:%d->%d\n",i,j);
            }
        }
    }
}
void dfs(struct Graph*g,int i)
{
int j;
    //printf("%d",pt);
printf("%d\t",i);
visited[i]=1;
for(j=0;j<g->V;j++)
{
    if((!visited[j])&& (*(g->Adj+i*g->V+j))==1)
    {
        dfs(g,j);
    }
}
}
void bf_traverse(struct Graph*g)
{
    int v,i;
    for(i=0;i<g->V;i++)
    {
        state[i]=0;
    }
    printf("Enter starting node\n");
    scanf("%d",&v);
    bfs(g,v);
}
void enqueue(int i)
{
if(f==-1 && r==-1)
{
    f=r=0;
    queue[r]=i;
}
else
{
    r++;
    queue[r]=i;
}
}
int dequeue()
{
    int item;
    if(f==-1 && r==-1)
    {
        printf("Underflow\n");
    }
    else if(f==r)
    {
        item=queue[f];
        f=r=-1;
    }
    else
    {
        item=queue[f];
        f++;
    }
    return item;
}
int isEmpty()
{
    if(f==-1 && r==-1)
        return 1;
        else return 0;
}
void bfs(struct Graph*g,int v)
{
    int i;
    enqueue(v);
    state[v]=1;
    while(!isEmpty())
    {
        v=dequeue();
        printf("%d\t",v);
        state[v]=2;
        for(i=0;i<g->V;i++)
        {
        if((*(g->Adj+v*g->V+i))==1 && state[i]==0)
        {
            enqueue(i);
            state[i]=2;
        }

        }
    }
}
int main()
{
    struct Graph*g;
    g=create();
    printSolution(g);
    printf("\n");
    printPath(g);
    int i,j;
    for(i=0;i<g->V;i++)
    {
        visited[i]=0;
    }
    // i can copy the Graph g to a 2d matrix which could be declared globally and can use it.
  /*  for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
            mai[i][j]=*(g->Adj+i*g->V+j);
        }
    }*/
    printf("DFS traversal is:\n");
    dfs(g,0);
    bf_traverse(g);
}
