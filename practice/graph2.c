#include<stdio.h>
#include<stdlib.h>
#define INF 9999
struct Graph{
int V,E;
int *Adj;
};
void printSolution(struct Graph*g)
{
   int i,j;
    for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
            if(*(g->Adj+i*g->V+j)==INF)
            {
                printf("%7s","INF");
            }
            else
            {
            printf("%7d",*(g->Adj+i*g->V+j));
            }
        }
        printf("\n");
    }
}
void floydWarshall(struct Graph*g)
{
    int dist[4][4],i,j,k;
    for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
            dist[i][j]=*(g->Adj+i*g->V+j);
        }
    }
    for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
            for(k=0;k<g->V;k++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
     for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
           *(g->Adj+i*g->V+j) =dist[i][j];
        }
    }
    printSolution(g);

}
int main()
{
    struct Graph*g;
    int matrix[4][4]={{0,5,INF,10},
                 {INF,0,3,INF},
                 {INF,INF,0,1},
                 {INF,INF,INF,0}};
    int i,j;
    g=(struct Graph*)malloc(sizeof(struct Graph));
    g->V=g->E=4;
    g->Adj=malloc(g->V*g->V*sizeof(int));
    for(i=0;i<g->V;i++)
    {
        for(j=0;j<g->V;j++)
        {
            *(g->Adj+i*g->V+j)=matrix[i][j];
        }
    }
    printf("\tOriginal Adjacency Matrix:\n\n");
    printSolution(g);
    printf("\n");
    printf("\tAfter Floyd Warshall\n\n");
    floydWarshall(g);

}
