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
    ll cnt[100] = {};
    cnt[0] = 2;
    cnt[1] = 1;
    int N;
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        cnt[i] = cnt[i-1] + cnt[i-2];
    }

    cout << cnt[N] << endl;


    return 0;
}