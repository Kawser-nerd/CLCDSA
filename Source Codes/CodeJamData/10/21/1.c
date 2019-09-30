#include <stdio.h>
#include <string.h>

typedef struct tree tree;

struct tree{
	tree *left,*right;
	char name[110];
};

tree b[10000];
int bt,CT;

tree *serch(tree *root,char *s)
{
	tree *x;
	for(x=root->left;x;x=x->right)
	{
		if(strcmp(x->name,s)==0)
			return x;
	}
	return NULL;
}

tree *add(tree *root,char *s)
{
	tree *x=&b[++bt];
	strcpy(x->name,s);
	x->right=root->left;
	root->left=x;
	x->left=NULL;
	CT++;
	return x;
}

void being(char *s)
{
	char *t;
	int f=0;
	tree *r=&b[0],*x;
	do{
		s++;
		for(t=s;*t!='/' && *t!='\0';t++);
		if(*t=='\0')f=1;
		else *t='\0';
		x=serch(r,s);
		if(x==NULL)x=add(r,s);
		r=x;
		s=t;
	}while(f==0);
}

int main()
{
	int T,C=0,N,M,i;
	char s[200];
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		bt=0;b[0].left=b[0].right=NULL;b[0].name[0]='\0';
		printf("Case #%d: ",++C);
		scanf("%d %d",&N,&M);
		CT=0;
		for(i=1;i<=N;i++)
		{
			scanf("%s",s);
			being(s);
		}
		CT=0;
		for(i=1;i<=M;i++)
		{
			scanf("%s",s);
			being(s);
		}
		printf("%d\n",CT);
	}
	return 0;
}