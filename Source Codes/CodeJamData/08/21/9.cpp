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
typedef vector<PI> vii;

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

int main()
{
    int N;
    int n,A,B,C,D,x0,y0,M;
    int ile[3][3];
    scanf("%d",&N);
    FOR(cs,1,N) {
        scanf("%d%d%d%d%d%d%d%d",&n,&A,&B,&C,&D,&x0,&y0,&M);
        ll res = 0;
        REP(i,3) REP(j,3) ile[i][j] = 0;
        int x = x0, y = y0;
        ++ile[x%3][y%3];
        FOR(i,1,n-1) {
            x = (A*1ll*x%M + B) % M;
            y = (C*1ll*y%M + D) % M;
            ++ile[x%3][y%3];
        }

        REP(i,9) {
            FOR(j,i+1,8) {
                FOR(k,j+1,8)
                    if((i/3+j/3+k/3)%3 == 0 && (i%3+j%3+k%3)%3 == 0)
                            res += ile[i/3][i%3]*1ll*ile[j/3][j%3]*ile[k/3][k%3];
            }
        }
        
        REP(i,9) if(ile[i/3][i%3]>2) 
            res += ile[i/3][i%3]*1ll*(ile[i/3][i%3]-1)*(ile[i/3][i%3]-2)/6;
        
        
        printf("Case #%d: %I64d\n", cs, res);
    }
}



