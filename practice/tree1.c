#include<stdio.h>
#include<stdlib.h>
#define max 30
int count=0;
int kl=0;
int addsum=0;
int va=11;
int f=-1,r=0;
int sum=0;
int q[max];
int s[max];
int top=-1;
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root=NULL;

struct node*create()
{
    int value;
    printf("Enter value\n");
    scanf("%d",&value);
    if(value==-1)
        return NULL;
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=value;
    printf("Enter left child of :%d\n",value);
    n->left=create();
    printf("Enter right child of :%d\n",value);
    n->right=create();
    return n;
}
void inorder(struct node*root)
{
        if(root->left)
        inorder(root->left);
        printf("%d\t",root->data);
        if(root->right)
        inorder(root->right);
}
void inorderPredecessor(struct node*t)
{
    struct node*p,*store;
    int n;
    printf("Enter node to know the predecessor\n");
    scanf("%d",&n);
    while(n!=t->data)
    {
        if(n>t->data)
        {
            store=t;
            t=t->right;
        }
        else
        {
            t=t->left;
        }
    }
    if(t->left==NULL && t->right==NULL)
    {
        printf("%d",store->data);
    }
    else
    {
        if(t->left)
        {
            p=t->left;
        }
        while(p->right!=NULL)
        {
            p=p->right;
        }
        printf("%d",p->data);
}
}
void enqueue(struct node*t)
{
        q[r]=t;
        r++;

}
struct node*dequeue()
{
struct node*t;
f++;
t=q[f];
return t;
}
void bfs(struct node*root)
{
    struct node*t,*p;
   t=root;
   if(t!=NULL)
   {
       enqueue(t);
        while(r-1!=f)
        {
            p=dequeue();
            printf("%d",p->data);
            if(p->left)
                enqueue(p->left);
            if(p->right)
                enqueue(p->right);
        }

   }
   else
   {
       printf("BFS not possible\n");
   }
}
void push(int t)
{
    top++;
    s[top]=t;
}
void pop()
{
top--;
}
void viewStack()
{
  int i;
  for(i=0;i<=top;i++)
  {
      printf("Path: %d",s[i]);
  }
}
void pathWithGivenSum(struct node*t)
{

    int i;
    if(t==NULL)
        return;
        sum+=t->data;
        push(t->data);
        if(sum==va)
        {
           viewStack();
        }
        else
        {
                pathWithGivenSum(t->left);
                pathWithGivenSum(t->right);
            sum=sum-t->data;
            pop();
        }



}
int diameter(struct node*p)
{
    struct node*ld,*rd;
    int td;
    int lh,rh;
            if(p==NULL)
            {
            return 0;
            }
        lh=height(p->left);
        rh=height(p->right);
        ld=diameter(p->left);
        rd=diameter(p->right);
        td=maxx(lh+rh+1,maxx(ld,rd));
        return td;
}
int height(struct node*p)
{
            if(p==NULL)
            return 0;

            int lh,rh,th;
            lh=height(p->left);
            rh=height(p->right);
            if(lh>rh)
            {
                th=lh+1;
            }
            else
            {
                th=rh+1;
            }
            return th;

}
int maxx(int a,int b)
{
    if(a>b)
        return a;
    if(b>a)
        return b;
}
int count_leaves(struct node*p)
{

  if(p!=NULL)
  {
      if(p->left==NULL && p->right==NULL)
      {
          count++;
      }
      else
      {
          if(p->left)
          {
                count_leaves(p->left);
          }
          if(p->right)
          {
              count_leaves(p->right);
          }
      }
  }
   return count;
}
int kleaves(struct node*p)
{
if(p->left==NULL && p->right==NULL)
{
    return 1;
}
else
{
    int lc=kleaves(p->left);
    int rc=kleaves(p->right);
    int tlc=lc+rc;
    if(tlc==1)
    {
       printf("%d",p->data);
    }
}
}
int lca(struct node*t,int p,int q)
{
    if(t==NULL)
        return NULL;
    if(t->data ==p || t->data==q)
    {
        return t->data;
    }
    int left=lca(t->left,p,q);
    int right=lca(t->right,p,q);
    if(left!=NULL && right!=NULL)
        return t->data;
    else
    {
        return(left?left:right);
    }
}
int diagonal_sum(struct node*p)
{
    enqueue(p->data);
    enqueue(NULL);
    while(r-1!=f)
    {
        p=dequeue();
        if(p==NULL)
        {
            printDiagonalSum();
            enqueue(NULL);
        }
        while(p!=NULL)
        {
            sum+=p->data;
            if(p->left)
            {
                enqueue(p->left->data);
            }
            p=p->right;
        }
    }
}
void printDiagonalSum()
{
    int i;
    for(i=r;i<=f;i++)
    {
        printf("%d",q[i]);
    }
}
int sumtree(struct node*p)
{
if(p==NULL || (p->left==NULL && p->right==NULL))
    return 1;
int lsum=add(p->left);
int rsum=add(p->right);
int total=lsum+rsum;
if(total==p->data &&(sumtree(p->left) && sumtree(p->right)))
{
        return 1;
}
return 0;
}
int add(struct node*p)
{
    if(p==NULL)
        return 0;
        else
        {
    return( p->data+add(p->left)+add(p->right));
        }
}
int main()
{
    struct node*t;
    root=create();
    inorder(root);
   // bfs(root);
   // inorderPredecessor(root);
   // pathWithGivenSum(root);
   //int td;
   //td=diameter(root);
   //printf("Total diameter is: %d",td);
   printf("\n");
   //int k=count_leaves(root);
  // printf("Total leaves:%d",k);
// kleaves(root);
//printf("%d",lca(root,3,4));
//diagonal_sum(root);
int k=sumtree(root);
printf("%d",k);

}

