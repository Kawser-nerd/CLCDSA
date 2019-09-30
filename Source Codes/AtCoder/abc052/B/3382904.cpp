#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;

typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<ui> vui;
typedef vector<long> vl;
typedef vector<int> vi;

typedef pair<ull, ull> pull;
typedef pair<ll, ll> pll;
typedef pair<ui, ui> pui;
typedef pair<long, long> pl;
typedef pair<int, int> pi;

template <class T>
void printv(vector<T> vc) {
    for (auto e: vc) cout << e << " ";
    cout << endl;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int x = 0, maxi = 0;
    for (char c: s) {
        if (c == 'I') ++x;
        if (c == 'D') --x;
        maxi = max(maxi, x);
    }

    cout << max(maxi, 0) << endl;

    return 0;
}