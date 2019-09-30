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
    int n,k,q;
    cin >> n >> k >> q;
    vector<int>a(n+1);
    rep(i,n){
        cin >> a[i];
    }
    a[n] = -1;
    int ans = INT_MAX;
    for(auto x:a){
        if(x==-1)break;
        vector<int>b;
        vector<int>c;
        rep(i,n+1){
            if(a[i]>=x){
                b.push_back(a[i]);
            }else{
                sort(b.begin(),b.end());
                rep(j,b.size()-k+1){
                    c.push_back(b[j]);
                }
                b.clear();
            }
        }
        sort(c.begin(),c.end());
        if(c.size()>=q)ans = min(ans,c[q-1]-c[0]);
    }
    cout << ans << endl;
}