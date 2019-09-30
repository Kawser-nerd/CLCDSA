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
    vector<int> r(N);
    for (auto& x: r){
        cin >> x;
    }

    sort(r.rbegin(),r.rend());
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            sum += r[i] * r[i];
        } else {
            sum -= r[i] * r[i];
        }
    }
    double ans = sum * M_PI;
    printf("%.10lf\n",ans);

    return 0;
}