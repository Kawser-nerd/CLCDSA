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
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    int N;
    int a,b;
    cin >> N >> a >> b;
    int K;
    cin >> K;
    vector<int> P,cnt(N+1,0);

    string ans = "YES";
    cnt[a]++;
    cnt[b]++;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        P.push_back(x);
        cnt[P[i]]++;
        if (cnt[P[i]] >= 2) {
            ans = "NO";
        }
    }


    cout << ans << endl;

    

    return 0;
}