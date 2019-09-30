#include<stdio.h>

int a[32768];
char s[32768];
int b[8][8] = {
	{0, 1, 2, 3, 4, 5, 6, 7},
	{1, 4, 3, 6, 5, 0, 7, 2},
	{2, 7, 4, 1, 6, 3, 0, 5},
	{3, 2, 5, 4, 7, 6, 1, 0},
	{4, 5, 6, 7, 0, 1, 2, 3},
	{5, 0, 7, 2, 1, 4, 3, 6},
	{6, 3, 0, 5, 2, 7, 4, 1},
	{7, 6, 1, 0, 3, 2, 5, 4}
};

int cal(int n,int m) {
	int i,j,t1,t2,p1,p2,t,r;
	for(i=t=0;i<n;i++) t=b[t][a[i]];
	for(i=r=0;i<m;i++) r=b[r][t];
	if (r!=4) return 0;
	for(i=t=0;i<8 && i<m;i++) {
		for(j=0;j<n;j++) {
			t=b[t][a[j]];
			if (t==1) break;
		}
		if (j<n) break;
	}
	if (i>=8 || i>=m) return 0;
	p1=i,t1=j;
	for(i=t=0;i<8 && i<m;i++) {
		for(j=n-1;j>=0;j--) {
			t=b[a[j]][t];
			if (t==3) break;
		}
		if (j>=0) break;
	}
	if (i>=8 || i>=m) return 0;
	p2=i,t2=j;
	t=p1+p2+1;
	if (t1>=t2) t++;
	if (t>m) return 0;
	return 1;
}

int main() {
	int cs=0,N,n,m,i;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&n,&m);
		scanf("%s",s);
		for(i=0;i<n;i++) a[i]=s[i]-'i'+1;
		if (cal(n,m)) printf("Case #%d: YES\n",++cs);
		else printf("Case #%d: NO\n",++cs);
	}
	return 0;
}