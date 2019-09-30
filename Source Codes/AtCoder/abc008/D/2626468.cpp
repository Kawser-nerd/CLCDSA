#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(int i = 0; i < n; i++)




int n;
vector<int> x, y;
map<tuple<int, int, int, int>, int> dp;

int solve(int lx, int ly, int rx, int ry){
    if(dp.count({lx, ly, rx, ry}))return dp[{lx, ly, rx, ry}];
    
    int sum = 0;
    REP(i, n){
        if(lx <= x[i] && x[i] < rx && ly <= y[i] && y[i] < ry){
            int lu = solve(lx, ly, x[i], y[i]);
            int ld = solve(lx, y[i] + 1, x[i], ry);
            int ru = solve(x[i] + 1, ly, rx, y[i]);
            int rd = solve(x[i] + 1, y[i] + 1, rx, ry);
            
            sum = max(sum, lu + ld + ru + rd + (rx - lx) + (ry - ly) - 1);
        }
    }
    
    return dp[{lx, ly, rx, ry}] = sum;
}

int main() {
    int w, h;
    cin >> w >> h >> n;
    
    x.resize(n);y.resize(n);
    
    REP(i, n){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
    }
    
    cout << solve(0, 0, w, h) << endl;
}