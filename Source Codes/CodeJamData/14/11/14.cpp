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

int N, L;
char A[250][250], B[250][250], W[250][250];
multiset<string> S;

void init () {
	S.clear();
}

void solve () {
	scanf("%d%d", &N, &L);
	for(int i = 0; i < N; i++) scanf("%s", A+i);
	for(int i = 0; i < N; i++) scanf("%s", B+i);

	int res = 9999;
	for(int pv = 0; pv < N; pv++) {
		int c = 0;
		for(int i = 0; i < N; i++) sprintf(W[i], A[i]);
		for(int x = 0; x < L; x++) if(W[0][x] != B[pv][x]) {
			++c; for(int i = 0; i < N; i++) W[i][x] ^= 1;
		}
		
		S.clear();
		for(int i = 0; i < N; i++) S.insert(W[i]);
		for(int i = 0; i < N; i++) {
			auto it = S.find(B[i]);
			if(it == S.end()) { c = 9999; break; }
			S.erase(it);
		}

		res = min(res, c);
	}

	printf("Case #%d: ", TCC);
	if(res == 9999) printf("NOT POSSIBLE\n");
	else printf("%d\n", res);
	if(TCC % 7 == 0) fprintf(stderr, "%d\n", TCC);
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