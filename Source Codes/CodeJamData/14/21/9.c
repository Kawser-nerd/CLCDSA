#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char s[111][111];

int can(int ix,int iy) {
	int i=0,j=0,op=0,a,b,x,y;
	while(s[ix][i] && s[iy][j]) {
		if(s[ix][i]!=s[iy][j]) return -1;
		a=b=0;
		x=i; y=j;
		while(s[ix][i]==s[ix][x]) i++,a++;
		while(s[iy][j]==s[iy][y]) j++,b++;
		op+=a>b?a-b:b-a;
	}
	return (s[ix][i] || s[iy][j])?-1:op;
}

int compi(const void *A,const void *B) {
	const int *a=A,*b=B;
	if(*a<*b) return -1;
	if(*a>*b) return 1;
	return 0;
}

void solve() {
	int i,r=0,ix[100],a[111],z,c;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s",s[i]);
	for(i=1;i<n;i++) if(can(0,i)<0) {
		puts("Fegla Won");
		return;
	}
	memset(ix,0,sizeof(ix));
	while(s[0][ix[0]]) {
		for(i=0;i<n;i++) {
			z=ix[i];
			c=0;
			while(s[i][z]==s[i][ix[i]]) c++,ix[i]++;
			a[i]=c;
		}
		qsort(a,n,sizeof(int),compi);
		z=a[n/2];
		for(i=0;i<n;i++) r+=z>a[i]?z-a[i]:a[i]-z;
	}
	printf("%d\n",r);
}

int main() {
	int t,no=1;
	scanf("%d",&t);
	while(t--) printf("Case #%d: ",no++),solve();
	return 0;
}
