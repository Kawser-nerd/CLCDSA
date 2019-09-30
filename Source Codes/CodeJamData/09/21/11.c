#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char d[100*100];
char p[120][120];
int n;

struct a
{
	double x;
	char * s;
	struct a * l,* r;
};

struct a * parse(char * d,int s,int e)
{
	struct a * r;
	int k,j;
	r = malloc(sizeof(struct a));
//	for (k=s;k<=e;++k) printf("%c",d[k]); printf("\n");
	while (d[s]!='(') ++s;
	while (d[e]!=')') --e;
	++s;
	--e;
	sscanf(d+s,"%lf",&(r->x));
	while (s<e && (d[s]<'a' || d[s]>'z')) ++s;
	if (s<e)
	{
		k=s;
		while (d[k]>='a' && d[k]<='z') ++k;
		d[k]=0;
		r->s=d+s;
		while (d[k]!='(') ++k;
		s=k;
		j=1;
		while (d[k]!=')' || j!=0)
		{
			++k;
			if (d[k]=='(') ++j;
			if (d[k]==')') --j;
		}
		r->l=parse(d,s,k);
		r->r=parse(d,k+1,e);
	}
	else
	{
		r->s=NULL;
	}
	return r;
}

double get(struct a * r,double x)
{
	int i;
	x*=r->x;
	if (r->s==NULL) return x;
	for (i=0;i<n;++i) if (strcmp(r->s,p[i])==0) return get(r->l,x);
	return get(r->r,x);
}

int main()
{
	struct a * r;
	int tc,itc,l,a,i,j;
	scanf("%d\n",&tc);
	for (itc=1;itc<=tc;++itc)
	{
		printf("Case #%d:\n",itc);
		scanf("%d\n",&l);
		j=0;
		for(i=0;i<l;++i) 
		{
			gets(d+j);
			j+=strlen(d+j);
		}
		r=parse(d,0,j-1);
		scanf("%d\n",&a);
		for (i=0;i<a;++i)
		{
			scanf("%s",p[0]);
			scanf("%d",&n);
			for (j=0;j<n;++j) scanf("%s",p[j]);
			scanf("\n");
			printf("%.10lf\n",get(r,1.0));
		}
	}
	return 0;
}