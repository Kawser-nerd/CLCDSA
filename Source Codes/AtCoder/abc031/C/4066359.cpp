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
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    int ans = -INT_MAX;
    for (int i = 0; i < N; i++) {
        int t_sum1 = 0;
        pair<int,int> a_max = make_pair(0,-INT_MAX);
        for (int k = 0; k < N; k++) {
            if (i == k) continue;
            int left = min(i,k);
            int right = max(i,k);
            int t_sum2 = 0;
            int sum = 0;
            //Aoki???????????
            //
            for (int p = left; p <= right; p+=2) {
                t_sum2 += a[p];
            }
            for (int p = left+1; p <= right; p+=2) {
                sum += a[p];
            }
            if (sum > a_max.second) {
                //??????????????????
                a_max = make_pair(k,sum);
                t_sum1 = t_sum2;
            }
        }
        ans = max(ans,t_sum1);
    }
    cout << ans << endl;
    return 0;
}