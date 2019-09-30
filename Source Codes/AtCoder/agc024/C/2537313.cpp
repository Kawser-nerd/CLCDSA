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
vector<int>a;
ll solve(int x,int y){
    ll res = 0;
    if(x==y)return a[x];
    int mi = a[x];
    int ma = a[y];
    for(int i = y; i>=x; i--){
        if(i==x){
            res += ma;
        }
        else if(a[i]-a[i-1] >1){
            return -1;
        }else if(a[i]-a[i-1] == 1){
            continue;
        }else{
            res+=ma;
            ma = a[i-1];
        }
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    a.resize(n);
    rep(i,n){
        scanf("%d",&a[i]);
    }
    if(a[0]!=0){
        cout << -1 << endl;
        return 0;
    }
    int l = 1;
    int r;
    ll ans = 0;
    for(int i =1; i<n;i++){
        if(i==n-1){
            ll k = solve(l,n-1);
            //show(k);
            ans+=k;
        }else{
            if(a[i]>=a[i+1]){
                r = i;
                ll k = solve(l,r);
                //cout << l << " " << r << endl;
                //show(k);
                if(k==-1){
                    cout << -1 << endl;
                    return 0;
                }
                ans += k;
                l = i+1;
            }
        }
    }
    cout << ans << endl;
}