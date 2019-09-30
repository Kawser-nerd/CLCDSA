
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

const int nmx=103;
int T[nmx][nmx];
int n,k;
char buf[nmx];

int val(char x){
    if(x=='.') return 0;
    if(x=='R') return 1;
    if(x=='B') return 2;
    return -1;
}

const int DX[4]={0,1,1,-1};
const int DY[4]={1,0,1,1};

inline bool ok(int x,int y){
    return x>=0 && y>=0 && x<n && y<n;
}
bool find(int x,int y,int z,int d){
    int r=0;
    while(ok(x,y) && T[y][x]==z){
            x+=DX[d];
            y+=DY[d];
            r++;
    }
    return r >= k;
};


int main(){
    int z;
    scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        CLR(T, 0);
        scanf("%d%d",&n,&k);
        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        REP(y,n){
            scanf("%s",buf);
            REP(x,n){
                int v=val(buf[x]);
                T[x][n-y-1]=v;
            }

        }    
        REP(x,n){
            int last=n-1;
            FORD(y,n-1,0){
                if(T[y][x]){
                    swap(T[y][x],T[last][x]);
                    last--;
                }
            }
        }
        bool t[2];
        t[0]=0,t[1]=0;
        REP(i,2)REP(y,n)REP(x,n)REP(d,4) t[i]|=find(x,y,i+1,d);


        printf("Case #%d: ",zz+1);
        if(t[0]&&t[1])
            puts("Both");
        else if(t[0])
            puts("Red");
        else if(t[1])
            puts("Blue");
        else 
            puts("Neither");
        

    }
    return 0;
}
