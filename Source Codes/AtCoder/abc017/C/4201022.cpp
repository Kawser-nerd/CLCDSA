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
    int N,M;
    cin >> N >> M;
    vector<int> l(N),r(N),s(N);
    vector<int> sum(M+1,0);
    int total = 0;
    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i] >> s[i];
        l[i]--;r[i]--;
        total += s[i];
        sum[l[i]] += s[i];
        sum[r[i]+1] -= s[i];
    }

    for (int i = 0; i < M; i++) {
        sum[i+1] += sum[i];
    }
    cout << total - *min_element(sum.begin(),sum.end()-1) << endl;




    return 0;
}