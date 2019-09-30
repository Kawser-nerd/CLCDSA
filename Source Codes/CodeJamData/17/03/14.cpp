#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,a,b) for(int i=(a);i>=(b);i--)
#define RVC(i,S) for(int i=0;i<(S).size();i++)
#define RAL(i,u) for(int i=fr[u];i!=-1;i=e[i].next)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
     
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
/*============ Header Template ============*/

map<LL,LL> f;

int kase;
void solve() {
    printf("Case #%d: ",++kase);
    LL N,K;
    read(N);read(K);
    f.clear();f[N]=1;
    while(K) {
        map<LL,LL>::iterator it=f.end();it--;
        LL a=(it->first),c=(it->second);
        f.erase(it);LL p=(a-1)/2,q=a-1-p;
        if(K<=c) {
            printf("%lld %lld\n",max(p,q),min(p,q));
            return;
        } f[p]+=c;f[q]+=c;K-=c;
    }
}

int main() {
    int T;
    read(T);
    while(T--) solve();
    return 0;
}