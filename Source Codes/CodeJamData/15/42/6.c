#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

const double EPS = 1e-9;

int TC, T;
int Numbers;
double NeedV, NeedX, AnsA, AnsB;
double N[120][2];/*Rate, Temp*/
int i, x;

int QSN(double A[], double B[]){
	int i;
	for (i=1; i>=0; i--){
		if (A[i]>B[i]+EPS) return 1;
		if (A[i]+EPS<B[i]) return -1;
	}
	return 0;
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		
		scanf("%d%lf%lf", &Numbers, &NeedV, &NeedX);
		
		for (i=0; i<Numbers; i++) for (x=0; x<2; x++) scanf("%lf", &N[i][x]);
		
		if (Numbers==1){
			if (N[0][1]!=NeedX){
				puts("IMPOSSIBLE");
				continue;
			}
			printf("%.8lf\n", NeedV/N[0][0]);
			continue;
		}
		
		qsort(N, Numbers, sizeof(N[0]), QSN);
		
		if (N[0][1]>NeedX+EPS){
			puts("IMPOSSIBLE");
			continue;
		}
		if (N[1][1]+EPS<NeedX){
			puts("IMPOSSIBLE");
			continue;
		}
		
		if (N[0][1]+EPS<N[1][1]){
			AnsB = (NeedV*(NeedX-N[0][1])) / (N[1][0]*(N[1][1]-N[0][1]));
			AnsA = (NeedV-AnsB*N[1][0])/N[0][0];
			if (AnsA<AnsB) AnsA = AnsB;
			printf("%.8lf\n", AnsA);
			continue;
		}
		
		AnsA = NeedV/(N[0][0]+N[1][0]);
		printf("%.8lf\n", AnsA);
		
		
	}
	
	return 0;
}

