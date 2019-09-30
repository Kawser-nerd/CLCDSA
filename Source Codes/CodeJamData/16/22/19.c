#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 18

typedef struct
{
	int diff, a, b;
}Res;

int resCompare(Res r, Res s)
{
	if(r.diff < s.diff)
		return -1;
	if(r.diff > s.diff)
		return 1;
	if(r.a < s.a)
		return -1;
	if(r.a > s.a)
		return 1;
	if(r.b < s.b)
		return -1;
	if(r.b > s.b)
		return 1;
	return 0;
}

void replace(char *s, char from, char to)
{
	while(*s)
	{
		if(*s == from)
			*s = to;
		s++;
	}
}

Res solve(char *a, char *b)
{
	Res res;

	if(!*a || !*b)
	{
		res.diff = 0;
		res.a = 0;
		res.b = 0;
		return res;
	}
	if(*a != '?' && *b != '?')
	{
		if(*a == *b)
		{
			res = solve(a+1,b+1);
			res.a += pow(10,strlen(a+1)) * (*a - '0');
			res.b += pow(10,strlen(b+1)) * (*b - '0');
			return res;
		}
		else if(*a < *b)
		{
			replace(a+1,'?','9');
			replace(b+1,'?','0');
			res.a = atoi(a);
			res.b = atoi(b);
			res.diff = abs(res.a-res.b);
			return res;
		}
		else
		{
			replace(a+1,'?','0');
			replace(b+1,'?','9');
			res.a = atoi(a);
			res.b = atoi(b);
			res.diff = abs(res.a-res.b);
			return res;
		}
	}
	else if(*b != '?')	// && *a == '?'
	{
		Res resEq, resLess, resGreater;
		char aa[MAX_LENGTH+2],bb[MAX_LENGTH+2];

		strcpy(aa,a);
		strcpy(bb,b);
		*aa=*bb;
		resEq = solve(aa,bb);

		if(*b!='0')
		{
			strcpy(aa,a);
			strcpy(bb,b);
			*aa=*bb-1;
			resLess = solve(aa,bb);
		}
		else
			resLess.diff = resEq.diff + 1;

		if(*b!='9')
		{
			strcpy(aa,a);
			strcpy(bb,b);
			*aa=*bb+1;
			resGreater = solve(aa,bb);
		}
		else
			resGreater.diff = resEq.diff + 1;
		res = resEq;
		if(resCompare(res,resLess)>0)
			res = resLess;
		if(resCompare(res,resGreater)>0)
			res = resGreater;
		return res;
	}
	else if(*a != '?')	// && *b == '?'
	{
		Res resEq, resLess, resGreater;
		char aa[MAX_LENGTH+2],bb[MAX_LENGTH+2];

		strcpy(aa,a);
		strcpy(bb,b);
		*bb=*aa;
		resEq = solve(aa,bb);

		if(*a!='0')
		{
			strcpy(aa,a);
			strcpy(bb,b);
			*bb=*aa-1;
			resLess = solve(aa,bb);
		}
		else
			resLess.diff = resEq.diff + 1;

		if(*a!='9')
		{
			strcpy(aa,a);
			strcpy(bb,b);
			*bb=*aa+1;
			resGreater = solve(aa,bb);
		}
		else
			resGreater.diff = resEq.diff + 1;
		res = resEq;
		if(resCompare(res,resLess)>0)
			res = resLess;
		if(resCompare(res,resGreater)>0)
			res = resGreater;
		return res;
	}
	else
	{
		Res resEq, resLess, resGreater;
		char aa[MAX_LENGTH+2],bb[MAX_LENGTH+2];

		strcpy(aa,a);
		strcpy(bb,b);
		*aa=*bb='0';
		resEq = solve(aa,bb);

		strcpy(aa,a);
		strcpy(bb,b);
		*aa='0';
		*bb='1';
		resLess = solve(aa,bb);

		strcpy(aa,a);
		strcpy(bb,b);
		*aa='1';
		*bb='0';
		resGreater = solve(aa,bb);

		res = resEq;
		if(resCompare(res,resLess)>0)
			res = resLess;
		if(resCompare(res,resGreater)>0)
			res = resGreater;
		return res;
	}
}

int main()
{
	int tcase,T,L,i;
	char C[MAX_LENGTH+2], J[MAX_LENGTH+2];
	char sa[MAX_LENGTH+2], sb[MAX_LENGTH+2];
	Res res;

	scanf("%d",&T);
	getchar();
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%s %s",C,J);
		res = solve(C,J);
		L = strlen(C);
		sprintf(sa,"%d",res.a);
		sprintf(sb,"%d",res.b);
		printf("Case #%d: ", tcase);
		for(i=0;i<L-(int)strlen(sa);i++)
			putchar('0');
		printf("%s ",sa);
		for(i=0;i<L-(int)strlen(sb);i++)
			putchar('0');
		printf("%s\n",sb);
	}
	return 0;
}
