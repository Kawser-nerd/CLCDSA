#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>
#include <numeric>
#include <string>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )
#define llrep(i, a, b) for(ll i = (a); i < (b); ++i )
#define llrrep(i, a, b) for(ll i = (a); i > (b); --i )
#define llREP(i, a, b) for(ll i = (a); i <= (b); ++i )
#define llRREP(i, a, b) for(ll i = (a); i >= (b); --i )
#define ullrep(i, a, b) for(ull i = (a); i < (b); ++i )
#define ullrrep(i, a, b) for(ull i = (a); i > (b); --i )
#define ullREP(i, a, b) for(ull i = (a); i <= (b); ++i )
#define ullRREP(i, a, b) for(ull i = (a); i >= (b); --i )



int N, K;
int A[100010];

int main() {
    cin >> N;
    rep(i, 0, N) {
        cin >> A[i];
    }

    int r = 0;
    int lmax = 0;
    ull cnt = 0;
    for(int l = 0; l < N; l++) {
        while ((r < N-1) && (A[r+1] > A[r])) {
            r++;
        }
        cnt += r-l+1;
        if (l == r) {
            r++;
        }
    }
    cout << cnt << endl;
}