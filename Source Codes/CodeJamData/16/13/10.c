#include <stdio.h>

/* generate the next permutation, or return 0 if there is no
   lexicographically next permutation.
   destroys the incoming string.
   works with duplicates as well. */
int nextpermutation(int *a,int n) {
	int j,k,i,t;
	for(j=n-2;j>-1 && a[j]>=a[j+1];j--);
	if(j<0) return 0;
	for(i=n-1;a[j]>=a[i];i--);
	t=a[j]; a[j]=a[i]; a[i]=t;
	for(k=j+1,i=n-1;k<i;k++,i--) t=a[k], a[k]=a[i], a[i]=t;
	return 1;
}

int bff[1111],n;
int a[1111];

int check(int len) {
	int i,b;
	for(i=0;i<len;i++) {
		b=bff[a[i]];
		if(b!=a[(i+1)%len] && b!=a[(i+len-1)%len]) return 0;
	}
	return 1;
}

void solve() {
	int i,best=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&bff[i]),bff[i]--;
	for(i=0;i<n;i++) a[i]=i;
	do {
		for(i=1;i<=n;i++) if(check(i) && best<i) best=i;
	} while(nextpermutation(a,n));
	printf("%d\n",best);
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
