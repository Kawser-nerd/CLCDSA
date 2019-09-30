#include <stdio.h>
int n,c,C,i,t[2000];
int cmp(int *a, int *b) { return *a>*b?-1:*a<*b; };
int main() {
	scanf("%d",&C);
	for(c=1;c<=C;c++) {
		int p,k,l;
		long long res = 0;
		scanf("%d%d%d",&p,&k,&l);
		for(i=0;i<l;i++) scanf("%d",t+i);
		qsort(t,l,sizeof(int),cmp);
		for(i=0;i<l;i++) res += t[i] * ((i/k)+1);
		printf("Case #%d: %lld\n",c,res);
	}
	return 0;
}
