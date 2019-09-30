#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod{
	double val;
	char arg[12];
	struct nod *st, *dr;
} *Nod;

char str[11000];
int p;


Nod construct()
{
	Nod root = (Nod) calloc(1,sizeof(struct nod));
	int poz;
	char buf[20];

	while (str[p]!='(')
		p++;

	p++;

	while (str[p]==' ' || str[p]=='\n')
		p++;
	
	poz = p;
	while (str[p]!=' ' && str[p]!='\n' && str[p]!='(' && str[p]!=')')
		p++;
	//printf("1:%d %s\n",p,str+p);
	memset(buf,0,20);
	strncpy(buf,str+poz,p-poz);
	root->val = atof(buf);

	while (str[p]==' ' || str[p]=='\n')
		p++;
	
	//printf("2:%d %s\n",p,str+p);
	if (str[p]==')')
	{
		p++;
		return root;
	}

	poz = p;
	while (str[p]!=' ' && str[p]!='\n' && str[p]!='(' && str[p]!=')')
		p++;
	//printf("3:%d %s\n",p,str+p);
	strncpy(root->arg,str+poz,p-poz);

	while (str[p]==' ' || str[p]=='\n')
		p++;
	//printf("4:%d %s\n",p,str+p);
	if (str[p]==')')
	{
		p++;
		return root;
	}
	//printf("5:%d %s\n",p,str+p);
	root->st = construct();
	root->dr = construct();

	while (str[p]==' ' || str[p]=='\n')
		p++;

	if (str[p]==')')
	{
		p++;
		return root;
	}
	
	return root;
}

double parcurg(Nod root,int n,char arg[110][12])
{
	int i;

	if (!root)
		return 1;

	for (i=0;i<n;i++)
		if (strcmp(root->arg,arg[i])==0)
			return root->val * parcurg(root->st,n,arg);
	return root->val * parcurg(root->dr,n,arg);
}

int main ()
{
	int T,k,L,i,j,n;
	char line[110];
	char arg[110][12];
	Nod root;
	double rez;


	scanf("%d\n",&T);
	for (k=0;k<T;k++)
	{
		memset(str,0,11000);
		scanf("%d\n",&L);

		for (i=0;i<L;i++)
		{
			memset(line,0,110);
			fgets(line,110,stdin);
			strcat(str,line);
		}
		p=0;
		root = construct(str);

		printf("Case #%d:\n",k+1);
		scanf("%d\n",&L);
		for (i=0;i<L;i++)
		{
			scanf("%s",line);
			scanf("%d",&n);
			//printf("%s %d\n",line,n);
			for (j=0;j<n;j++)
				scanf("%s",arg[j]);
			rez= parcurg(root,n,arg);
			printf("%.7lf\n",rez);
		}

	}

	return 0;
}

