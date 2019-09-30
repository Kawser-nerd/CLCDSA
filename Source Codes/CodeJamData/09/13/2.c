#include<stdio.h>

#define MAXN 50

double comb[MAXN][MAXN];
int N,C;

void calc() {
	int i,j;
	for(i=0;i<MAXN;i++) {
		for(j=0;j<=i;j++) {
			if(j==0 || j==i) comb[i][j]=1;
			else comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
		}
	}
}

int usd[MAXN][MAXN][MAXN];
double mem[MAXN][MAXN][MAXN];

double fans(int x) {
	if(x==N) return 0;
	if(usd[x][N][C]) return mem[x][N][C];
	usd[x][N][C]=1;
	double sum=0, csum=0;
	int i;
	for(i=1;x+i<=N && i<=C;i++) {
		sum += comb[N-x][i]*comb[x][C-i]*(1+fans(x+i));
	}
	sum += comb[x][C];
	csum = comb[N][C]-comb[x][C];
	mem[x][N][C] = sum/csum;
	return sum/csum;
}

int main() {
	int t,T,l,i,j;
	char c;
	calc();
	scanf("%d",&T);
	for(t=1;t<=T;t++) {
		scanf("%d %d",&N,&C);
		printf("Case #%d: %.7lf\n",t,fans(0));
	}
	
	return 0;
}
