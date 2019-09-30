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

const int BASE=(1<<20);
int tree[2*BASE-1];

void treeInit() {
    FOR(i,0,2*BASE-1) tree[i]=0;
}

void dodaj(int x, int ile) {
    x += BASE;
    while(x>0) {
        tree[x]+=ile;
        x>>=1;
    }
}

int ileMniejszych(int x) {
    x += BASE;
    int r=0;
    while(x>1) {
        if(x%2==1) r += tree[x-1];
        x>>=1;
    }
    return r;
}

int ileRownych(int x) {
    if(x<0) return 0;
    return tree[x+BASE];
}

int size() {
    return tree[1];
}

int elementNumer(int k) {
    if(k<0) return 0;
    int x=1;
    while(x<BASE) {
        x<<=1;
        if(k>=tree[x]) {
            k -= tree[x];
            ++x;
        }
    }
    return x-BASE;
}

int odp[1000100];

int main()
{
    int T,x,K,n;
    scanf("%d",&T);
    FOR(cs,1,T) {
        scanf("%d",&K);
        scanf("%d",&n);
        treeInit();
        vi res;
        REP(i,n) { scanf("%d",&x); res.pb(x); }
        FOR(i,1,K) dodaj(i,1);
        int cur = 1;
        REP(i,K) {
            // i + 1;
            //printf("size: %d\n" ,size());
            //printf("ilemniejszcyh(%d) = %d\n", cur, ileMniejszych(cur));
            int idx = elementNumer((ileMniejszych(cur)+i)%size());
            odp[idx] = i+1;
            dodaj(idx,-1);
            cur = idx;
        }
        
        printf("Case #%d:", cs);
        FORE(it,res) printf(" %d", odp[*it]);
        printf("\n");
    }
}

