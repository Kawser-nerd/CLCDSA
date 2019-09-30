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
    int N,L;
    cin >> N >> L;
    vector<string> S(N);
    string ans = "";
    for (int i = 0; i < N; i++){
        cin >> S[i];
    }
    sort(all(S));
    for (int i = 0; i < N; i++){
        ans += S[i];
    }
    cout << ans << endl;



    return 0;
}