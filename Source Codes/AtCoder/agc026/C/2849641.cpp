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
    string s;
    cin >> n >> s;
    map<pair<string,string>,ll>mp;
    rep(i,1<<n){
        string a,b;
        rep(j,n){
            if(i&(1<<j)){
                a+=s[j];
            }else{
                b+=s[j];
            }
        }
        reverse(b.begin(),b.end());
        mp[make_pair(a,b)]++;
    }
    ll ans = 0;
    rep(i,1<<n){
        string a,b;
        rep(j,n){
            if(i&(1<<j)){
                a+=s[j+n];
            }else{
                b+=s[j+n];
            }
        }
        reverse(b.begin(),b.end());
        ans += mp[make_pair(b,a)];
    }
    cout << ans << endl;
}