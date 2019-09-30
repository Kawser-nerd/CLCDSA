#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define fr(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define alll(v) v.begin(),v.end()
#define mp(a,b) make_pair(a,b)
#define rdd(a) ll a; cin>>a
#define rrd rdd(a);rep(i,a)
using namespace std;
template<class X>void pr(X x){cout<<x<<endl;}
template<class X>void prr(X x){for(auto it:x){cout<<it<<endl;}}

int main(){
    string s;
    cin>>s;
    ll num=0,n2=0;
    vector<char> v;
    unordered_map<char, int> m;
    rep(i, s.size()){
        if(m.count(s[i])==0){
            m.insert(mp(s[i],1));
            num++;
            v.push_back(s[i]);
        }else{
            m[s[i]]++;
        }
    }
    for (auto it:v) {
        if(m[it]%2==1) n2++;
    }
//    prr(v);
//    pr(n2);
    ll nonkisuu = s.size()-n2;
//    pr(nonkisuu);
//    pr(n2);
    if (n2!=0) pr( 2 * int(int(nonkisuu/2) / (n2)) + 1);
    else pr(nonkisuu);
    return 0;
}