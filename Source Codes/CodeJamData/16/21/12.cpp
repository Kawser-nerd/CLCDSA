#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

map<char, int> mp;

int dec(char c, string s) {
    int u = mp[c];
    for (char d: s) {
        mp[d] -= u;
    }
    return u;
}
string solve() {
    string s;
    cin >> s;
    mp.clear();
    for (char c: s) {
        mp[c]++;
    }
    int deg[10] = {};
    deg[0] = dec('Z', "ZERO");
    deg[4] = dec('U', "FOUR");
    deg[5] = dec('F', "FIVE");
    deg[6] = dec('X', "SIX");
    deg[7] = dec('V', "SEVEN");
    deg[2] = dec('W', "TWO");
    deg[3] = dec('R', "THREE");
    deg[1] = dec('O', "ONE");
    deg[8] = dec('G', "EIGHT");
    deg[9] = dec('E', "NINE");
    for (auto k: mp) {
        if (k.second) {
            cerr << s << endl;
            for (int i = 0; i < 10; i++) {
                cerr << deg[i] << " ";
            }
            cerr << endl;
        }
        assert(k.second == 0);
    }

    string ans;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < deg[i]; j++) {
            ans += '0'+i;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: %s\n", t, solve().c_str());
    }
    return 0;
}