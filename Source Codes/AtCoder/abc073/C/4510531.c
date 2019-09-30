#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int ai;
	int time;
	struct node*left;
	struct node*right;
}tree;
tree* create(int now)
{
	tree*r=(tree*)malloc(sizeof(tree));
	r->ai=now;
	r->time=1;
	r->left=NULL;
	r->right=NULL;
	return r;
}
void add(tree*root,int now)
{
	if(root->ai==now)
	{
		root->time++;
		return;
	}
	if(root->ai<now)
	{
		if(root->right!=NULL)
		{
			add(root->right,now);
			return;
		}
		else
		{
			root->right=create(now);
			return;
		}
	}
	else
	{
		if(root->left!=NULL)
		{
			add(root->left,now);
			return;
		}
		else
		{
			root->left=create(now);
			return;
		}
	}
}
int allxian=0;
void searchall(tree*root)
{
	if(root==NULL)
		return;
	searchall(root->left);
	searchall(root->right);
	if(root->time%2!=0)
	{
		allxian++;
	}
}
int main()
{
	int alla[100001];
	int allcount=0;
	int i,j;
	int now;
	tree*root;
	scanf("%d",&allcount);
	scanf("%d",&now);
	root=create(now);
	for(i=0;i<allcount-1;i++)
	{
		scanf("%d",&now);
		add(root,now);
	}
	searchall(root);
	printf("%d",allxian);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:72:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&allcount);
  ^
./Main.c:73:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&now);
  ^
./Main.c:77:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&now);
   ^