#include <stdio.h>
#include <string.h>
#include <gmp.h>

int x[50];
int v[50];
int hopeless[50];

int main () {

	int C,N,K,B,T;
	int c,i,j,k,l;
	int switchCount,hopelessCount;
	
	fscanf( stdin, "%d ", &C);
	
	for ( c = 0 ; c < C ; c++ ) {
		
		printf("Case #%d:",c+1);
		memset(x,0,sizeof(int)*50);
		memset(v,0,sizeof(int)*50);
		memset(hopeless,0,sizeof(int)*50);
		switchCount = 0;
		hopelessCount = 0;
		
		fscanf( stdin, "%d %d %d %d ", &N, &K, &B, &T);
		for ( i = 0 ; i < N; i++ ) {
			fscanf( stdin, "%d ", &x[i]);
		}
		for ( i = 0 ; i < N; i++ ) {
			fscanf( stdin, "%d ", &v[i]);
		}	
		
		for ( i = 0 ; i < N; i++ ) {
			if ( v[i] * T + x[i] < B ) {
				hopeless[i] = 1;
				hopelessCount++;
			} 
		}
		
		int doneFor = 0;
		for ( i = N-1 ; i >= 0 ; i-- ) {
			if (hopeless[i] == 0 ) {
				for ( j = i+1 ; j<N ; j++ ) {
					if ( hopeless[j]  ) {
						switchCount++;
					}
				}
				doneFor++;
			} 
			if ( doneFor >= K ) {
				break;
			}
		}
		
		if ( N - hopelessCount < K ) {
			printf(" IMPOSSIBLE");
		} else {
			printf(" %d",switchCount);
		}
		
		printf("\n");
		
	}
	
	return 0;
}