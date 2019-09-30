#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <array>
using namespace std;
typedef long long unsigned int llui_t;
typedef long long int lli_t;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

/* inputs */
llui_t N;
vector<llui_t> C, S, F;

llui_t solve(llui_t n, llui_t t) {
    if (n == N-1) {
        return t;
    } else {
        llui_t tt;
        if (t <= S[n]) {
            tt = S[n] + C[n];
        } else {
            tt = (t / F[n] + (t % F[n] == 0 ? 0 : 1)) * F[n] + C[n];
        }
        return solve(n+1, tt);
    }
}


int main() {
    cin >> N;

	for(llui_t i=0; i<N-1; i++) {
		llui_t c, s, f;
		cin >> c >> s >> f;
		C.push_back(c);
        S.push_back(s);
        F.push_back(f);
	}

	for(llui_t i=0; i<N; i++) {
        cout << solve(i, 0) << endl;
	}
}