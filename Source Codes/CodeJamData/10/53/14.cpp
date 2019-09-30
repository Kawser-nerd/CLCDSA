
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

const int M = 1001000; 
const int M2 = M * 2; 
int cc[M * 4]; 

int main()
{
    int T;  
    scanf("%d", &T); 

    FOR(tc,1,T) {
        int C;  
        scanf("%d",&C); 
        CLR(cc,0); 

        REP(i,C) { 
            int x,H; 
            scanf("%d%d",&x,&H); 
            cc[x + M2] += H; 
        } 
        int i = 0;
        LL ret = 0; 
        while (i < M * 4) { 
            if (cc[i] <= 1) ++i; 
            else { 
                cc[i-1] += cc[i] / 2; 
                cc[i+1] += cc[i] / 2; 
                ret += cc[i] / 2; 
                cc[i] %= 2;             
                --i;              
            }
        } 
        printf("Case #%d: %lld\n",tc,ret); 
    } 

	return 0;
}

