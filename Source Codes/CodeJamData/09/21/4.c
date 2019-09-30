#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct treeT {
	double p;
	char feature[16];
	struct treeT *y, *n;
};

struct treeT * parse(char * s, int n)
{
	struct treeT * r = (struct treeT *)malloc(sizeof(struct treeT));
	char *p, *pr;
	sscanf(s, "%lf%s", &r->p, r->feature);
	p = s;
	while( (*p != '(') && (p < s+n) )
		++p;
	if(*p == '(')
	{
		n = 1;
		pr = p + 1;
		while(n)
		{
			if(*pr == '(')
				++n;
			if(*pr == ')')
				--n;
			++pr;
		}
		r->y = parse(p+1, pr-p-2);
		p = pr;
		while(*p != '(')
			++p;
		n = 1;
		pr = p + 1;
		while(n)
		{
			if(*pr == '(')
				++n;
			if(*pr == ')')
				--n;
			++pr;
		}
		r->n = parse(p+1, pr-p-2);
	}
	else
	{
		r->y = r->n = NULL;
	}
	return r;
}

double check(struct treeT * tree, double sp, int F, char feats[][16])
{
	int f;
	sp *= tree->p;

	if(!tree->y)
		return sp;

	for(f = 0; f < F; ++f)
	{
		if(!strcmp(tree->feature, feats[f]))
			break;
	}
	if(f < F)
		return check(tree->y, sp, F, feats);
	return check(tree->n, sp, F, feats);
}

int main(void)
{
	char s[8192];
	int N, n;

	fgets(s, 8192, stdin);
	sscanf(s, "%d", &N);

	for(n = 1; n <= N; ++n)
	{
		int L, l, Z, A, a;
		char * p = s;
		char * pr;
		struct treeT * tree;
		fgets(s, 8192, stdin);
		sscanf(s, "%d", &L);
		Z = 8192;
		for(l = 0; l < L; ++l)
		{
			fgets(p, Z, stdin);
			Z -= strlen(p);
			p += strlen(p);
		}
		printf("Case #%d:\n", n);
		p = s;
		pr = p + strlen(p);
		while(*p != '(')
			++p;
		while(*pr != ')')
			--pr;
		tree = parse(p + 1, pr - p - 1);
		fgets(s, 8192, stdin);
		sscanf(s, "%d", &A);
		for(a = 0; a < A; ++a)
		{
			int F, f;
			char feats[100][16];
			double p;
			scanf("%s", s);
			scanf("%d", &F);
			for(f = 0; f < F; ++f)
			{
				scanf("%s", feats[f]);
			}
			fgets(s, 8192, stdin);
			p = check(tree, 1., F, feats);
			printf("%.7lf\n", p);
		}
	}

	return 0;
}
