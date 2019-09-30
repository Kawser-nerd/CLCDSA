#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <ctime>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
//#define mp make_pair
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
#define println(X) cout<<X<<endl;
#define DBG(X) cout<<#X<<" : "<<X<<endl;
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;
const double PI = acos(-1);

bool comp(int a, int b){
    if(a%2==1 && b%2==0) return true;
    if(a%2==0 && b%2==1) return false;
    return a <b;
}

int main(){
    string s;
    cin>>s;
    vi v(26, 0);
    rep(i, s.size()) v[s[i]-'a']++;
    sort(all(v), comp);
    // rep(i, 26){
    //     cout<<" "<<v[i];
    // }
    // cout<<endl;
    vi u, w;
    for(int i = 0; i < 26; i++){
        if(v[i]==0)continue;
        if(v[i]%2==1){
            u.pb(1);
            v[i]-=1;
        }
        v[i]/=2;
        rep(j, v[i]){
            sort(all(u));
            if(u.size()==0) u.pb(2);
            else u[0]+=2;
        }
    }
    sort(all(u));
    cout<<u[0]<<endl;
    // for(int i = 0; i < u.size(); i++){
    //     cout<<" "<<u[i]<<endl;
    // }
}