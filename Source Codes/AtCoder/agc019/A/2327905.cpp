#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,n) for(int i=n;i>=a;--i)
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define mod 1000000007
#define show(n) cerr<<#n<<" = "<<n<<endl
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl
#define showsp(n) for(auto z:n){cerr<<z.fs<<" "<<z.sc<<", ";}cerr<<endl;

//????AtCoder??define
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vd = vector<double>;
using pint = pair<int,int>;

const int INF = (1 << 30);

int maxn = 1000000000;

ll tgt;
vector<pair<double,pair<double,ll> > > e(4);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    rep(i,4) {
        e[i].sc.fs=(1<<i)/4.0;
        cin>>e[i].sc.sc;
        e[i].fs=e[i].sc.sc*(4.0/(1<<i));
        //cerr<<e[i].sc.fs<<endl;
    }
    cin>>tgt;
    //showsp(e);
    sort(all(e));
    //showsp(e);
    //show(e[0].fs);
    ll cur=0;
    ll are;
    rep(i,4){
        are=tgt/e[i].sc.fs;
        cur+=e[i].sc.sc*are;
        tgt-=e[i].sc.fs*are;
    }
    cout<<cur<<endl;
    return 0;
}