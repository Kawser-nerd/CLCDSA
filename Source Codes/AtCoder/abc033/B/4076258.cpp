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
    int N;
    cin >> N;
    vector<int> P(N);
    vector<string>S(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> S[i] >> P[i];
        sum += P[i];
    }

    string ans = "atcoder";
    for (int i = 0; i < N; i++) {
        if (P[i] >= sum/2+1) {
            ans = S[i];
        }
    }
    cout << ans << endl;

    return 0;
}