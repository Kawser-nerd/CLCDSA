#include <stdio.h>
#include <string.h>
#include <memory.h>
int len;
int nn[111];
int uu[111];
int ccc = 0;
void chk(int );
void plus(int a, int p) {
	for (int i=0;i<len;i++) {
		uu[a+i] += nn[i] * p * 2;
	}
	uu[a+a] += p*p;
	nn[a] += p;
}
void bak(int a) {
	for (int i=0;i<len*2-1;i++) {
		if (uu[i] >= 10) return;
	}

	if (a > len-1-a) {
		ccc ++;
		chk(len * 2 - 1); 
		return;
	}
	if (a != 0) {
		nn[a] = 0;
		bak(a+1);
	}
	for (int w=1;w<=2;w++) {
		plus(a, 1);
		if (a != len-1-a)plus(len-1-a, 1);
		bak(a+1);
	}
	plus(a, -2);
	if (a != len-1-a)plus(len-1-a, -2);
}

int T;
char cA[10001][111], cB[10001][111];
int A[10001][111], B[10001][111];
int lA[10001], lB[10001];
int sol[10001];
int main() {
	freopen("C-large-2.in","r",stdin);
	freopen("C-large-2.out","w",stdout);

	scanf("%d",&T);
	for (int i=0;i<T;i++){
		scanf("%s %s",cA[i],cB[i]);
		lA[i] = strlen(cA[i]);
		lB[i] = strlen(cB[i]);
		for (int j=0;j<lA[i];j++) A[i][j] = cA[i][j] - '0';
		for (int j=0;j<lB[i];j++) B[i][j] = cB[i][j] - '0';
	}
	memset(uu, 0, sizeof(uu));
	memset(nn, 0, sizeof(nn));
	for (int i=1;i<=3;i++) {
		nn[0] = i;
		uu[0] = i*i;
		chk(1);
	}
	memset(uu, 0, sizeof(uu));
	memset(nn, 0, sizeof(nn));
	for (len = 2;len <= 50; len ++) {
		//ccc = 0;
		bak(0);
	//	fprintf(stderr, "%d\n", ccc);
	}
	for (int i=0;i<T;i++) {
		printf("Case #%d: %d\n", i+1, sol[i]);
	}
	return 0;
}

bool cccxy(const int *X, int lX, const int *Y, int lY) { // <=
	if (lX < lY) return true;
	if (lX > lY) return false;
	for (int i=0;i<lX;i++) {
		if (X[i] != Y[i]) {
			return X[i] < Y[i];
		}
//		fprintf(stderr, "%p %p %d\n", X, Y, i);
//		if(i>2) while(1);
	}
	return true;
}
void chk(int L) {
	for (int i=0;i<T;i++) {
		if (cccxy(A[i], lA[i], uu, L) && cccxy(uu, L, B[i], lB[i])) {
			sol[i] ++;
		}
	}
}