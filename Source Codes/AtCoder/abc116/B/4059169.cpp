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
    vector<int> a;
    a.push_back(N);

    int i = 0;
    int ans = 0;
    while(1) {
        if (a[i] == 4 || a[i] == 2 || a[i] == 1) {
            ans = i+4;
            break;
        } else {
            int v;
            if (a[i] % 2 == 0){
                v = a[i]/2;
            } else {
                v = 3*a[i]+1;
            }
            a.push_back(v);
        }
        ++i;
    }
    cout << ans << endl;

    return 0;
}