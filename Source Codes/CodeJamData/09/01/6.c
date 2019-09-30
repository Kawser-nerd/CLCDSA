#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,D,L;
char* word[6000];

static int cmpstringp(const void *p1, const void *p2)
{
	/* The actual arguments to this function are "pointers to
	   pointers to char", but strcmp(3) arguments are "pointers
	   to char", hence the following cast plus dereference */
	
	return strcmp(* (char * const *) p1, * (char * const *) p2);
}

void init()
{
	int i;
	scanf("%d%d%d",&L,&D,&N);
	for(i=0;i<D;i++) {
		word[i]=malloc(sizeof(char)*20);
		scanf("%s",word[i]);
	}
	qsort(word,D,sizeof(char *),cmpstringp);
}

int beg, end;

int find(char c, int l, int r, int k)
{
	if (l>=r) return 0;
	int m=(l+r)/2, t,lbeg,lend;
	
	if (word[m][k]<c) return find(c,m+1,r,k);
	else if (word[m][k]>c) return find(c,l,m,k);
	else {
		t=find(c,l,m,k);
		if (t==0) lbeg=m;
		else lbeg=beg;

		t=find(c,m+1,r,k);
		if (t==0) lend=m+1;
		else lend=end;
	}
	beg=lbeg;
	end=lend;
	return 1;
}

int count(char *pat,int l,int r,int k)
{
	int t,s,lbeg,lend;
	char *npat;

	if (!*pat) return 1;
	else if (*pat=='(') {
		for(npat=pat;*npat!=')';npat++);
		npat++;
		s=0;
		
		for(pat++;*pat!=')';pat++) {
			t=find(*pat,l,r,k);
			lbeg=beg;
			lend=end;
			if (t) s+=count(npat,lbeg,lend,k+1);
		}
		return s;
	}
	else {
		t=find(*pat,l,r,k);
		lbeg=beg;
		lend=end;
		if (t) return count(pat+1,lbeg,lend,k+1);
		else return 0;
	}
}

void solve()
{
	char buf[500];
	
	int i;
	for(i=0;i<N;i++) {
		scanf("%s", buf);
		printf("Case #%d: %d\n", i+1, count(buf,0,D,0));
	}
}

int main()
{
	init();
	solve();

	return 0;
}
