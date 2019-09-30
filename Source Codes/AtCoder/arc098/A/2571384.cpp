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
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>a(n);
    vector<int>b(n);
    a[0] = b[0] = 0;
    rep(i,n){
        if(i){
            a[i] = a[i-1];
            b[i] = b[i-1];
        }if(s[i]=='W'){
            a[i]++;
        }else{
            b[i]++;
        }
    }
    int ans = INT_MAX;
    ans = min(b[n-1]-b[0],a[n-2]);
    for(int i = 1;i < n-1;i++){
        ans = min(ans, a[i-1]+b[n-1]-b[i]);
    }
    cout << ans << endl;
}