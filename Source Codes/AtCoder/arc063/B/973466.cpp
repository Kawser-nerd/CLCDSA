#include "math.h"
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <set>

#define ifor(i, a, b) for (int i = (a); i < (b); i++)
#define rfor(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long double ld;
typedef long long int lli;
typedef complex<double> P;
const double eps = 1e-11;
int vex[4] = {1, 0, -1, 0};
int vey[4] = {0, 1, 0, -1};
typedef vector<double> Vec;
typedef vector<int> vec;
typedef vector<Vec> MAT;
typedef vector<vec> mat;
lli MOD = 1000000007;
int main() {
    lli n,t;
    cin >> n >> t;
    lli a[100005];
    lli b[100005];
    lli c[100005];

    c[n] = 0;
    rep(i,n)cin >> a[i];

    b[0] =  a[0];
    rep(i,n-1)b[i+1] = min(b[i],a[i+1]);
    rrep(i,n)c[i] = max(c[i+1],a[i]);
    rep(i,n-1){
        cerr << b[i] << ' ' << c[i+1] << endl;
    }
    vector<pair<lli,pair<lli,lli>>> data;
    rep(i,n-1)data.push_back(make_pair(c[i+1]-b[i],make_pair(c[i+1],b[i])));
    sort(data.begin(),data.end());
    reverse(data.begin(),data.end());
    map<lli,lli> map1,map2;
    rep(i,n-1){
        if(data[0].first == data[i].first) {
            map1[data[i].second.first]++;
            map2[data[i].second.first]++;
        }else{
            break;
        }
    }
    cout << min(map1.size(),map2.size())<<endl;
}