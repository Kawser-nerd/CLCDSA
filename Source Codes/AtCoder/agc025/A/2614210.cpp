#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int hoge(string s){
    int ans = 0;
    rep(i,s.size()){
        ans += s[i]-'0';
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int ans = INT_MAX;
    for(int i = 1; i < n; i++){
        ans = min(ans, hoge(to_string(i)+to_string(n-i)));
    }
    cout << ans << endl;
}