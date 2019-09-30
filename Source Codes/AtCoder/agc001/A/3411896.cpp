#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>

#define P 1000000007

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

int n;
int main() {
    cin >> n; 
    vi vc; vc.resize(2*n);

    for (int i = 0; i < 2*n; ++i) cin >> vc[i];

    sort(vc.begin(), vc.end());

    int ans = 0;
    int temp = INT_MAX;
    for (int i = 0; i < 2*n; ++i) {
        if (i % 2) {
            ans += min(temp, vc[i]);
            
        } else {
            temp = vc[i];
        }
    }

    cout << ans << endl;

    return 0;
}