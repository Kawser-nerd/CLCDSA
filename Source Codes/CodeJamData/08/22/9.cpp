#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#include <ext/hash_map>
#include <ext/hash_set>

using namespace std;
typedef pair<int,int> PI;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i,n)	for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,s,k)	for(int i=(s),_k=(k);i<=_k;++i)
#define FORD(i,s,k)	for(int i=(s),_k=(k);i>=_k;--i)
#define FORE(it,q)	for(__typeof((q).begin()) it=(q).begin();it!=(q).end();++it)
#define FORED(it,q) for(__typeof((q).rbegin())it=(q).rbegin();it!=(q).rend();++it)
#define SIZE(x)     x.size()
#define ALL(v)      v.begin(),v.end()
#define SE          second
#define FI          first
#define pb          push_back

int max_p = 1000000;
int Fu[1100000];
void FuInit() { REP(i,max_p+10) Fu[i] = -1; }
int FuFind(int a) { if(Fu[a]<0) return a; Fu[a] = FuFind(Fu[a]); return Fu[a]; }
void FuUnion(int a, int b) {
    a = FuFind(a); b = FuFind(b);
    if(a == b) return;
    if(Fu[b] < Fu[a]) swap(a,b);
    Fu[a] += Fu[b];
    Fu[b] = a;
}

int S[1000100];
int prime[1000100];

int main()
{
    int C;
    ll a,b,p;
    vi P;
    FOR(i,0,max_p) prime[i] = -1;
    prime[2] = 1;
    P.pb(2);
    for(int i = 4; i <= max_p; i += 2) prime[i] = 0;
    for(int i = 3; i <= max_p; i += 2) if(prime[i]<0) {
        prime[i] = 1;
        P.pb(i);
        for(int j=2*i; j <= max_p; j += i)
            prime[j] = 0;
    }
    int size = SIZE(P);
    scanf("%d",&C);
    FOR(cs,1,C) {
        scanf("%I64d%I64d%I64d",&a,&b,&p);
        int s = (int)sqrt(b);
        FuInit();
        int cur = 0;
        while(cur < size && P[cur] < p) ++cur;
        while(cur < size && P[cur] <= b) {
            ll k = a + (a%P[cur]==0?0:(P[cur] - a%P[cur]));
            for(ll i = k; i <= b; i += P[cur]) {
                FuUnion(i-a,k-a);
            }
            ++cur;
        }
        int res = 0;
        REP(i,b-a+1) if(Fu[i] < 0) ++res;
        printf("Case #%d: %d\n", cs, res);
    }
}

