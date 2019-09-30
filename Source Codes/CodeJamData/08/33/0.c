#include <stdio.h>
#define r 1000000007
#define N (1<<21)
int w[N*2];
void ins(int x, int val) {
	int v = N + x;
	w[v] = (w[v] + val) % r;
	while(v!=1) {
		v/=2;
		w[v] = (w[2*v] + w[2*v+1]) % r;
	}
}
int query(int a, int b) {
	int va = N + a, vb = N + b;
	int wyn = w[va];
	if(va != vb) wyn += w[vb], wyn %= r;
	while(va/2 != vb/2) {
		if(va % 2 == 0) wyn += w[va+1], wyn %= r;
		if(vb % 2 == 1) wyn += w[vb-1], wyn %= r;
		va /= 2; vb /= 2;
	}
	return wyn;
}
int n,c,C,i,m;


long long int A[500005],X,Y,Z;
int B[500005];
//int D[500005];
int E[500005];
int F[500005];
int cmp(int *a, int *b) { return B[*a]<B[*b]?-1:B[*a]>B[*b]; }
int main() {
	scanf("%d",&C);
	for(c=1;c<=C;c++) {
		int j;
		long long res1 = 0;
		scanf("%d%d%lld%lld%lld",&n,&m,&X,&Y,&Z);
		memset(w,0,sizeof(w));
		for(i=0;i<m;i++) scanf("%d",A+i);
		for(i=0;i<n;i++) {
			B[i] = A[i%m];
			E[i] = i;
//			printf("%d ",B[i]);
			A[i%m] = (X * A[i%m] + Y * (i + 1)) % Z;
		}
		qsort(E,n,sizeof(int),cmp);
		int num = 0;
		F[E[0]] = 0;
		for(i=1;i<n;i++) {
			num += B[E[i-1]] < B[E[i]];
			F[E[i]] = num;
		}
		ins(0,1);
		for(i=0;i<n;i++) {
			long long res = query(0,F[i]);
			ins(F[i]+1,res);
			res1 += res;
			res1 %= r;
		}
		printf("Case #%d: %lld\n",c,res1);
	}
	return 0;
}
