#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <queue>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )
#define ullrep(i, a, b) for(ull i = (a); i < (b); ++i )
#define ullrrep(i, a, b) for(ull i = (a); i > (b); --i )
#define ullREP(i, a, b) for(ull i = (a); i <= (b); ++i )
#define ullRREP(i, a, b) for(ull i = (a); i >= (b); --i )


int main() {
    string s;
    int K;
    cin >> s;
    cin >> K;
    std::vector<string> L;
    ullrep(i, 0, s.size()) {
        ullrep(j, 0, K) {
            L.push_back(s.substr(i, j+1));
        }
    }
    sort(L.begin(), L.end());
    auto end = std::unique(L.begin(), L.end());
    cout << *(L.begin() + K - 1) << endl;
}