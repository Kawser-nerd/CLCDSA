#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define memset0(x) memset(x, 0, sizeof (x));

int TC, TCC;

int N, A[1005];


void init () {
}

void solve () {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", A+i);

	int v = 0;
	for(int i = 0; i < N; i++) if(A[i] > i) v += (A[i] >= (i+N)/2) ? -1 : 1;

	printf("Case #%d: %s\n", TCC, (v >= 21) ? "BAD" : "GOOD");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &TC);
	while(++TCC <= TC) {
		init();
		solve();
	}
	return 0;
}