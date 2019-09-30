#include<cassert>
#include<random>
#include<deque>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

void print(__int128 x) {
    string o;
    while (x > 0) {
	o += '0' + x % 10;
	x /= 10;
    }
    reverse(o.begin(), o.end());
    if (o.empty()) o = "0";
    puts(o.c_str());
}
int N;
LL X;
LL A[200011];
LL sums[200011];

void MAIN() {
    scanf("%d%lld", &N, &X);
    REP (i, N) scanf("%lld", A+i);
//    N = 200000;
//    X = 1000000000;
//    mt19937 engine(3);
//    REP (i, N) A[i] = engine() % 1000000000;
//

    sort(A, A+N);
    REP (i, N) sums[i+1] = sums[i] + A[i];

    LL ans = 1LL<<60;
    for (int block=1; block<=N; block++) {
	int r = N, l = r - block;
	__int128 tmp = (sums[r]-sums[l]) * 5 + X * block;;
	r = l; l -= block;
	for (LL c=5; r>0; c+=2) {
	    amax(l, 0);
	    tmp += __int128(sums[r]-sums[l]) * c;
	    r = l;
	    l -= block;
	}
	if (ans > tmp) ans = tmp;
    }
           
    ans += X * N;
    printf("%lld\n", (LL)ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}