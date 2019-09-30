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
    int N,X;
    cin >> N >> X;
    vector<int> a(N);
    for (auto& x: a) {
        cin >> x;
    }

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (X & (1<<i)){
            sum += a[i];
        }
    }
    cout << sum << endl;




    return 0;
}