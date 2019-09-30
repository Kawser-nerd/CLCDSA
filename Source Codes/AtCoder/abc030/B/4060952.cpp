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
    int n,m;
    cin >> n >> m;
    n %= 12;
    double rpml = 360.0/60,rpms = 360.0/12/60;
    double t1 = ((double)n * 60 + m) * rpms,t2 = (double)m * rpml;
    double ans = abs(t1-t2);
    if (ans > 180){
        ans = 360 - ans;
    } 
    cout << ans << endl;



    return 0;
}