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

int main() {
    cin >> N;

    vector<vector<lli_t>> F(N, vector<lli_t>(10));
    vector<vector<lli_t>> P(N, vector<lli_t>(10));

	for(llui_t i=0; i<N; i++) {
        for(llui_t j=0; j<10; j++) {
            cin >> F[i][j];
        }
    }

	for(llui_t i=0; i<N; i++) {
        for(llui_t j=0; j<11; j++) {
            cin >> P[i][j];
        }
    }

    lli_t ans = -1e11;
    for(unsigned i=1; i<pow(2,10); i++) {
        lli_t p = 0;
        for(int k=0; k<N; k++) {
            int n = 0;
            for(int j=0; j<10; j++) {
                n += (i>>j & F[k][j]);
            }
            p += P[k][n];
        }
        ans = max(p, ans);
    }
    cout << ans << endl;

}