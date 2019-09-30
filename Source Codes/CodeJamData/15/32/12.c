#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a, b) (a > b ? a : b)

int P[100];
int MAX;

void record( char ANS[], char target[] ) {
    int n = strlen(ANS),
	m = strlen(target);

    if( m > n ) return;

    int i, cnt = 0;
    for( i = 0; i <= n- m; i++ )
	if( strncmp(&ANS[i], target, m) == 0 )
	    cnt++;
    
    MAX = max(MAX, cnt);
    
    P[cnt]++;
}

void backtrack( int k, char Q[], char ANS[], int N, char target[] ) {
    
    if( k == N ) {
	record(ANS, target);
	return ;
    }

    int cand = strlen(Q);
    
    int i;
    for( i = 0; i < cand; i++ ) {
	ANS[k] = Q[i];
	backtrack(k + 1, Q, ANS, N, target);
    }

}

int main( void ) {
    int T;
    scanf("%i", &T);

    int t;
    for( t = 1; t <= T; t++ ) {
	int K, L, S;
	scanf("%i %i %i", &K, &L, &S);
	
	char s[K + 1], target[L + 1];
	scanf("%s %s", s, target);
	
	double tot = pow(K, S);

	memset(P, 0, sizeof(P));
	char A[100] = {0};
	MAX = 0;

	backtrack(0, s, A, S, target);

	double ans = 0.0;

	int i;
	for( i = 0; i <= 10; i++ )
	    ans += i * P[i] / tot;

	printf("Case #%i: %.9f\n", t, MAX - ans);
    }

    return 0;
}
