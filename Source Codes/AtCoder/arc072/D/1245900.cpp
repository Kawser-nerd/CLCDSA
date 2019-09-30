#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long LL;
typedef pair<double, LL> PDL;
deque<PDL> dq;
const int maxn = 5*1e5 + 100;
double ans, t[maxn];
LL V, v[maxn], L;
inline PDL Mix(PDL x){
    PDL y = dq.back();
    ans -= y.fi*y.se;
    dq.pop_back();
    V -= y.se;
    return mp((x.fi*x.se+y.fi*y.se)/(x.se+y.se), x.se+y.se);
}

inline void prePush(PDL x){
    V += x.se;
    while(V > L){
        PDL &y = dq.front();
        if(V-y.se <= L){
            LL Vt = V-L;
            ans -= y.fi*Vt;
            V = L;
            y.se -= Vt;
        } else {
            ans -= y.fi*y.se;
            V -= y.se;
            dq.pop_front();
        }
    }
}
int n;
int main(){
    cin>>n>>L;
    for(int i = 0; i < n; i++) cin>>t[i]>>v[i];
    dq.push_back(mp(t[0], v[0]));
    ans = t[0]*v[0]; V = L;
    printf("%.7f\n", ans/L);
    for(int i = 1; i < n; i++){
        PDL x = mp(t[i], v[i]);
        prePush(x);
        while(dq.size() > 0 && dq.back().fi >= x.fi) x = Mix(x);
        dq.push_back(x);
        ans += x.fi*x.se;
        V = L;
        printf("%.7f\n", ans/L);
    }
}