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

int stk[50];
int top;

inline void printN() {
    LL res=0;
    PER(i,top,1) res=res*10+stk[i];
    printf("%lld\n",res);
}

int kase;
void solve() {
    printf("Case #%d: ",++kase);
    LL n;
    read(n);
    top=0;
    LL k=n;
    for(;n;n/=10) stk[++top]=(n%10);
    stk[top+1]=0;int ps=top;
    PER(i,top,2) {
        if(stk[i]!=stk[i+1]) ps=i;
        if(stk[i]>stk[i-1]) {
            stk[ps]--;
            PER(j,ps-1,1) stk[j]=9;
            printN();return;
        }
    }
    printf("%lld\n",k);
}

int main() {
    int T;
    read(T);
    while(T--) solve();
    return 0;
}