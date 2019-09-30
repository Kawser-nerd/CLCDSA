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

//????AtCoder??define
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pint = pair<int,int>;

const int INF = (1 << 30);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,k;
    cin>>n>>k;
    vector<ll> vec(100001);
    ll a,b;
    rep(i,n){
        scanf("%lld %lld", &a,&b);
        vec[a]+=b;
    }
    REP(i,1,100001){
        if(k<=vec[i]){
            cout<<i<<endl;
            break;
        }
        k-=vec[i];
    }

    return 0;
}