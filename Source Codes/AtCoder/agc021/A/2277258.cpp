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

    ull n;
    cin>>n;
    ull t=1;
    ll c=1;
    int cnt=1;
    int ans=1;
    while(true){
        //show(t);
        if(cnt==9){
            c*=10;
            cnt=0;
        }
        if(t<=n&&n<t+c){
            cout<<ans<<endl;
            return 0;
        }
        t+=c;
        cnt++;
        ans++;
    }

    return 0;
}