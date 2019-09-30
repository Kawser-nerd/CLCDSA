#include <stdio.h>
#include <string.h>

/* generate the next permutation, or return 0 if there is no
   lexicographically next permutation.
   destroys the incoming string.
   works with duplicates as well.  */
int nextpermutation(char *a,int n) {
	int j,k,i;
	char t;  /* datatype of permutation */
	for(j=n-2;j>-1 && a[j]>=a[j+1];j--);
	if(j<0) return 0;
	for(i=n-1;a[j]>=a[i];i--);
	t=a[j]; a[j]=a[i]; a[i]=t;
	for(k=j+1,i=n-1;k<i;k++,i--) t=a[k], a[k]=a[i], a[i]=t;
	return 1;
}

void solve() {
	char S[100],t[100];
	int n,N,r,p,s,i,j,len;
	scanf("%d %d %d %d",&n,&r,&p,&s);
	N=1<<n;
	j=0;
	for(i=0;i<p;i++) S[j++]='P';
	for(i=0;i<r;i++) S[j++]='R';
	for(i=0;i<s;i++) S[j++]='S';
	S[j]=0;
	do {
		strcpy(t,S);
		len=N;
		while(len>1) {
			for(i=j=0;i<len;i+=2,j++) {
				if(t[i]+t[i+1]=='P'+'R') t[j]='P';
				else if(t[i]+t[i+1]=='P'+'S') t[j]='S';
				else if(t[i]+t[i+1]=='R'+'S') t[j]='R';
				else goto next;
			}
			len=j;
		}
		puts(S);
		return;
	next:;
	} while(nextpermutation(S,N));
	puts("IMPOSSIBLE");
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
