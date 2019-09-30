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

char s[1005];
int ai[1005];

int kase;
void solve() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	REP(i,1,n) ai[i]=(s[i]=='-');
	int K;read(K);int cnt=0;
	REP(i,1,n-K+1) {
		if(ai[i]) {
			REP(j,i,i+K-1) ai[j]^=1;++cnt;
		}
	}
	printf("Case #%d: ",++kase);
	REP(i,1,n) if(ai[i]) {
		printf("IMPOSSIBLE\n");return;
	} printf("%d\n",cnt);
}

int main() {
	int T;
	read(T);
	while(T--) solve();
	return 0;
}