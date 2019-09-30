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
    int a,b,c;
    cin >> a >> b >> c;
    int ans;
    if (a == b && b == c && c == a)ans = 1;
    else if (a != b && b != c && c != a) ans = 3;
    else {
        ans = 2;
    }
    cout << ans << endl;




    return 0;
}