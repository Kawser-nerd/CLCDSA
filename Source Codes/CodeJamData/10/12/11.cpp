
// headers {{{
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cctype>
#include <cstring>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long double LD;
typedef long long LL;
typedef pair<LD,LD> PD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;

#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FORE(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)

#define ALL(x) x.begin(),x.end()
#define CLR(A,v) memset((A),v,sizeof((A)))
#define FI first
#define MP make_pair
#define PB push_back
#define SE second
#define SIZE(x) ((int)(x).size())
// }}}
const int nmx=103,rmx=260;
int n, D, I, M;
int A[nmx];
int T[nmx][rmx];
const int inf=10000000;

int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        
               // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        scanf("%d%d%d%d",&D,&I,&M,&n);
        REP(i,n+1) REP(j,rmx) T[i][j]=inf;
         REP(i,rmx) T[0][i]=0;

        REP(i,n) scanf("%d",A+i);
        REP(i,n){
            int mm=M;
            if(mm==0) mm=1;
            REP(iter, 2*rmx/mm){   // DODAJEMY
                REP(f,rmx){
                    FOR(t,max(0,f-M), min(f+M, rmx-1))
                        T[i][t]=min(T[i][t], T[i][f]+I);    
                    }
            }
            REP(f, rmx){
                if( abs(f-A[i]) <= M) T[i+1][A[i]]=min( T[i+1][A[i]], T[i][f]); // zostawienie
                T[i+1][f] = min( T[i][f] + D, T[i+1][f]);   // usuniecie
                FOR(t,max(0,f-M), min(f+M, rmx-1)){
                    T[i+1][t] = min(T[i+1][t], T[i][f] + abs(t - A[i])); // modyfikacja
                }
            
            }
        }


        int res=inf;
        REP(i,rmx) res=min(res, T[n][i]);
        printf("Case #%d: %d\n",zz+1,res);
    }
    return 0;
}
