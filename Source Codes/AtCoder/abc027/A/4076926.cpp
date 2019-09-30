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
    int l1,l2,l3;
    cin >> l1 >> l2 >> l3;
    int ans;
    if (l1 == l2) {
        ans = l3;
    } else if (l2 == l3) {
        ans = l1;
    } else if (l1 == l3) {
        ans = l2;
    }
    cout << ans << endl;


    return 0;
}