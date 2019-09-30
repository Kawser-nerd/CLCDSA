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

int W[300010];
int E[300010];
int S[300010];
int N;
int main() {
    cin >> N;
    char tmp;
    cin >> tmp;
    if (tmp == 'W') {
        W[0] = 1;
        E[0] = 0;
    }else{
        W[0] = 0;
        E[0] = 1;
    }
    rep(i, 1, N) {
        char c;
        cin >> c;
        if (c == 'W') {
            W[i] = W[i-1]+1;
            E[i] = E[i-1];
        }else{
            W[i] = W[i-1];
            E[i] = E[i-1]+1;
        }
    }
    int m = min(E[N-1]-E[0], W[N-2]);

    rep(i, 1, N-1) {
        m = min(m, W[i-1]+E[N-1]-E[i]);
    }
    cout << m << endl;
}