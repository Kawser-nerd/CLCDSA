#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    int N,Q;
    cin >> N >> Q;
    vector<int> L(Q),R(Q),T(Q);
    vector<int> ans(N,0);
    for (int i = 0; i < Q; ++i) {
        cin >> L[i] >> R[i] >> T[i];
        for (int k = L[i]-1; k < R[i]; k++) {
            ans[k] = T[i];
        }
    }
    
    for (auto x : ans) {
        cout << x << endl;
    }


    

    return 0;
}