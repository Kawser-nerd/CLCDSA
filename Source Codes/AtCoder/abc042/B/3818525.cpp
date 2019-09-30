#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <cmath>

#define MOD 1000000007

using namespace std;

typedef long long ll;

typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

typedef pair<ll, ll> pll;
typedef pair<int, int> pi;

typedef vector<pll> vpl;
typedef vector<pi> vpi;

typedef queue<ll> ql;
typedef queue<int> qi;

template <class T>
void printv(vector<T> vc) {
    for (auto e: vc) cout << e << " ";
    cout << endl;
}

template <class T>
void printvv(vector<T> vvc) { 
    for (auto vc: vvc) {
        for (auto e: vc) cout << e << " ";
        cout << endl;
    }
}

template <class T>
void printvp(vector<pair<T, T> > vp) {
    for (auto pT: vp) cout << pT.first << " " << pT.second << endl;
}

int main() {
    int n, l;
    cin >> n >> l;
 
    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
        cin >> vs[i];
    }
 
    sort(vs.begin(), vs.end());
    for (auto word: vs) cout << word;
    cout << endl;
 
    return 0;
}