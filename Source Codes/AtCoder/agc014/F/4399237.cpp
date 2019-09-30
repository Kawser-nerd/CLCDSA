#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int N;
int A[200011];
int R[200011];

int ring(int a, int b, int c) {
    return (a<b) + (b<c) + (c<a);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;
    REP (i, N) R[A[i]] = i;
    R[N] = N;
    int f = N;
    int ans = 0;
    for (int i=N; i--;) {
	if (ans == 0) {
	    if (R[i] > R[i+1]) {
		ans = 1;
		f = i+1;
	    }
	} else {
	    if (ring(R[f], R[i], R[i+1]) == 1) {
		ans++;
		f = i+1;
	    }
	}
    }
    printf("%d\n", ans);
}

int main() {
    MAIN();
    return 0;
}