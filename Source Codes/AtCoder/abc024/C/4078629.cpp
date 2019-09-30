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
    int N,D,K;
    cin >> N >> D >> K;
    vector<int> L(D),R(D),S(K),T(K), ans(K);
    vector<bool> d(K);
    for (int i = 0; i < D; i++) {
        cin >> L[i] >> R[i];
    }

    for (int i = 0 ; i < K; i++) {
        cin >> S[i] >> T[i];
        if (S[i] < T[i]) {
            d[i] = true;
        }
    }
    for (int i = 0; i < D; i++) {
        for (int k = 0; k < K; k++) {
            if (d[k]) {
                if (S[k] >= L[i] && S[k] <= R[i] && S[k] < T[k]) {
                    S[k] = R[i];
                    ans[k] = i+1;
                }
            } else if(!d[k]) {
                if (S[k] >= L[i] && S[k] <= R[i] && S[k] > T[k]) {
                    S[k] = L[i];
                    ans[k] = i+1;
                }
            }

        }
    }
    for (auto x : ans) {
        cout << x << endl;
    }




    return 0;
}