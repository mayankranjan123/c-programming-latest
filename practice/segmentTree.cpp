#include<iostream>
using namespace std;
void buildTree(int*arr,int*tree,int start,int endd,int treeNode)
{
if(start==endd)
{
    tree[treeNode]=arr[start];
    return;
}
else
{
    int mid;
    mid=(start+endd)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,endd,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
}
void update(int *arr,int *tree,int node,int start,int end,int idx,int value)
{
    if(start==end)
    {
        arr[idx]=value;
        tree[node]=value;
    }
    else
    {
        int mid;
        mid=(start+end)/2;
        if(start<=idx && idx<=mid)
        {
            update(arr,tree,2*node,start,mid,idx,value);
        }
        else
        {
            update(arr,tree,2*node+1,mid+1,end,idx,value);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
int query(int*tree,int node,int start,int end,int l,int r)
{
   if(l>end||start>r)
return 0;
if(l<=start&&r>=end)
return tree[node];
int p1,p2;
int mid=(start+end)/2;
p1=query(tree,2*node,start,mid,l,r);
p2=query(tree,2*node+1,mid+1,end,l,r);
return p1+p2;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int *tree=new int[18];
    buildTree(arr,tree,0,8,1);
    int i,sum;

 /*   for(i=1;i<18;i++)
    {
        cout<<tree[i]<<endl;
    }
    */
   cout<<query(tree,1,0,8,0,8)<<endl;
   update(arr,tree,1,0,8,5,12);
   cout<<query(tree,1,0,8,0,8);
}
