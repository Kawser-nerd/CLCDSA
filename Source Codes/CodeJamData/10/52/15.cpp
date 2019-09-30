
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

const int max_n = 101000; 
const int inf = (1<<30); 
int c[max_n]; 

int M,T,N; 
LL L; 
int a[max_n]; 

int main()
{
    scanf("%d", &T);

    FOR(tc,1,T) { 
        scanf("%lld%d",&L, &N);
        cerr<<tc<<endl;  
        REP(i,N) scanf("%d",&a[i]); 
        sort(a, a + N); 
        M = a[N-1]; 
        REP(i,M) c[i] = inf;         
        c[0] = 0; 
        set<PII> s; 
        REP(i,M) s.insert(MP(c[i],i)); 

        while (!s.empty()) { 
            PII x = *s.begin(); 
            s.erase(s.begin()); 
            if (x.FI == inf) break; 
            int sm, cs; 
            REP(i,N) { 
                sm = x.SE + a[i]; 
                cs = x.FI + 1; 

                if (sm >= M) { 
                    sm -= M; 
                    cs -= 1; 
                } 

                if (c[sm] > cs) { 
                    s.erase(s.find(MP(c[sm], sm))); 
                    c[sm] = cs; 
                    s.insert(MP(c[sm], sm)); 
                } 
            } 
        } 
        printf("Case #%d: ",tc); 
        if (c[L % M] == inf) puts("IMPOSSIBLE"); 
        else { 
            printf("%lld\n",(L / M) + c[L % M]); 
        } 
    } 

	return 0;
}

