#include <iostream>

using namespace std;
typedef long long ll;

struct mypt {
        int x;
        int y;
};

bool on_line(mypt a, mypt b, mypt t) {
        return (t.x-a.x)*(t.y-b.y) - (t.y-a.y)*(t.x-b.x) == 0;
}

pair<ll,ll> egcd(ll a, ll b) {
        ll s0=1,s1=0,s2=a;
        ll t0=0,t1=1,t2=b;
        while (t2 != 0) {
                ll q=s2/t2;
                ll r0=t0,r1=t1,r2=t2;
                t0=s0-q*t0,t1=s1-q*t1,t2=s2-q*t2;
                s0=r0,s1=r1,s2=r2;
        }

        return pair<ll,ll>(s0,s1);
}

ll mod_inv(ll x, ll m) {
        x %= m;
        pair<ll,ll> p = egcd(x,m);
        return (p.first%m+m)%m;
}

const int MAXN=2e2+2+2;
const ll MOD=998244353;
int N;
mypt p[MAXN];

ll twos[MAXN];
ll tot_weight[MAXN];
ll line_weight[MAXN];

int main() {
        cin >> N;
        for (int i=0; i<N; ++i)
                cin >> p[i].x >> p[i].y;

        twos[0] = 1;
        for (int i=1; i<MAXN; i++)
                twos[i] = (2*twos[i-1])%MOD;

        tot_weight[0] = 0;
        tot_weight[1] = 0;
        for (int i=2; i<MAXN; ++i)
                tot_weight[i] = (twos[i]+MOD-i-1)%MOD;


        for (int i=0; i<MAXN; ++i)
                line_weight[i] = (mod_inv(i*(i-1)/2,MOD)*tot_weight[i])%MOD;


        ll subs = tot_weight[N];
        for (int a=0; a<N; ++a) {
                for (int b=a+1; b<N; ++b) {
                        int line_ct=0;
                        for (int c=0; c<N; ++c) {
                                if (on_line(p[a],p[b],p[c])) {
                                        line_ct++;
                                }
                        }

                        subs = (subs + MOD - line_weight[line_ct])%MOD;
                }
        }

        cout << subs << "\n";
}