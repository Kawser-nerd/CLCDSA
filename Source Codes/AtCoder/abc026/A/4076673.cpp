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
    int a;
    cin >> a;
    int ans = 0;
    for (int i = 1; i <= a; i++) {
        int y = a-i;
        ans = max(ans,i*y);
    }
    cout << ans << endl;




    return 0;
}