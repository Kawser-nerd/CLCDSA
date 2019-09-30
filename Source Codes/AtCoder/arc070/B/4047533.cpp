#include <iostream>
#include <bitset>
#include <algorithm>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

const int MAX_N = 5005;

#define getchar getchar_unlocked

inline int in() {
    int n = 0; short c;
    while ((c = getchar()) >= '0') n = n * 10 + c - '0';
    return n;
}

int a[MAX_N], sm[MAX_N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n = in(), K = in(), id = 0;
    rep(i,n){
        a[id] = in();
        if(a[id] < K-1) id++;
    }
    n = id;
    sort(a, a+n, greater<int>());
    rrep(i,n){
        sm[i] = sm[i+1] + a[i];
    }
    int ans = 0;
    bitset<MAX_N> dp;
    dp[0] = true;
    rep(i,n){
        if(K+a[i]-sm[i] > 0){
            bool flag = true;
            srep(j,max(0, K-sm[i]),K+a[i]-sm[i]){
                if(dp[j]){
                    flag = false;
                    break;
                }
            }
            ans += flag;
        }
        dp |= (dp << a[i]);
    }
    cout << ans << "\n";
    return 0;
}