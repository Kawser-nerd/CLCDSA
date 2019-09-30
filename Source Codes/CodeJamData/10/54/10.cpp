
// Headers {{{
#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
using namespace std;
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define CLR(A,v) memset((A),v,sizeof((A)))
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SIZE(x) (int)(x.size())
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
typedef long double LD; 
typedef vector<string> VS;
// }}}

bool vis[10][10]; // vis[position][digit]
int B; 

bool can_add(int a) { 
   int g = 0; 
   while (a) { 
       if (vis[g][a % B]) return false; 
       a /= B; 
       ++g; 
   } 
   return 1; 
} 

void set_a(int a, bool val) {     
    int g = 0; 
    while (a) { 
        vis[g][a%B] = val; 
        a /= B; 
        ++g; 
    } 
} 

int count(int lf, int last) { 
    int ret = 0; 
    FOR(i,last+1,lf) { 
        if (can_add(i)) { 
            if (i == lf) ++ret; 
            else { 
                set_a(i, true); 
                ret += count(lf - i, i); 
                set_a(i, false); 
            } 
        } 
    } 
    return ret; 
} 


int main()
{
    int T,N; 

    scanf("%d", &T); 
    FOR(tc,1,T) { 
        scanf("%d%d",&N,&B); 
        CLR(vis,0); 
        printf("Case #%d: %d\n",tc,count(N,0)); 
    } 


	return 0;
}

