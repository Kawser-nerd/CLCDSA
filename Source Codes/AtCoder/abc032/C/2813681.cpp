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
int S[100010];

int main() {
    cin >> N >> K;
    rep(i, 0, N) {
        cin >> S[i];
        if (S[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }

    ull mul = 1;
    int right = 0;
    int maxl = 0;
    for (int left = 0; left < N; left++) {
        while (mul * S[right] <= K && right < N) {
            mul *= S[right++];
        }
        maxl = right-left > maxl? right-left : maxl;
        if (right == left) ++right;
        else mul /= S[left];
    }
    cout << maxl << endl;
}