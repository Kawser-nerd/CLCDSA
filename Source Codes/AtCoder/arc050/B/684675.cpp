#include <cstring>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <functional>
#include <numeric>
#include <iomanip>
#include <iterator>
#include <array>
using namespace std;
#define rt return
#define FOR(i,j,k) for(int i=j; i<(int)k;++i)
#define rep(i,j) for(int i=0;i<(int)j;++i)
#define rep1(i,j) for(int i=1;i<=(int)j;++i)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define pb_ push_back
#define eb_ emplace_back
#define fi_ first
#define se_ second
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define p_ printf
#define s_ scanf
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool f(ll R, ll B, ll x, ll y, ll D){
    rt D <= (R - D) / (x - 1) + (B - D) / (y - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll R, B;
    while(cin >> R >> B){
        ll x, y;
        cin >> x >> y;
        
        ll l = 0, r = min(R,B)+1, m;
        while(r - l > 1){
            m = (l + r) / 2;
            (f(R,B,x,y,m) ? l : r) = m;
        }
        cout << l << endl;
    }
}