#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TCs, TC;
int N, K;
double prob[210];
double vote[210][210];/*Y, N*/
int choose[210];
int i, x, y;
double ans;

void Try(){
	int i, x, K2;
	K2 = K/2;
	for (i=0; i<K; i++) for (x=0; x<K; x++) vote[i][x] = 0.0;
	vote[0][0] = 1.0;
	
	for (i=0; i<K; i++){
		for (x=0; x<=i; x++){
			vote[x+1][i-x] += vote[x][i-x]*prob[choose[i]];
			vote[x][i-x+1] += vote[x][i-x]*(1.0-prob[choose[i]]);
		}
		
	}
	
	if (vote[K2][K2]>ans) ans = vote[K2][K2];
	return ;
}

int QSP(double *A, double *B){
	if (*A>*B) return -1;
	if (*A<*B) return 1;
	return 0;
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	scanf("%d", &TCs);
	for (TC=1; TC<=TCs; TC++){
		printf("Case #%d: ", TC);
		scanf("%d%d", &N, &K);
		for (i=0; i<N; i++) scanf("%lf", &prob[i]);
		
		qsort(prob, N, sizeof(prob[0]), QSP);
		
		for (i=0; i<K; i++) choose[i] = N+i-K;
		
		ans = -1.0;
		Try();
		
		for (i=0; i<K; i++){
			choose[i] = i;
			Try();
		}
		
		printf("%.8lf\n", ans);
	}
	
	return 0;
}


