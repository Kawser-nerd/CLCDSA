
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





VI typ;


void go(int a,int b){
    if(a<b) swap(a,b);
    if(b==0){ typ.PB(1); return;}
    int x=a/b;
    go(b,a%b);
    if(x==1) typ.PB(0);
    else typ.PB(1);
    
}   

bool win(int a,int b){
    typ.clear();
    go(a,b);
    int n=SIZE(typ);
    int r=0;
    int x=n-1;
    while(typ[x]==0){
        x--;
        r++;
    }
    return r%2==0;
}


int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----


        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        int a1,a2,b1,b2;
        scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
        LL r=0;
        int was=b1;
        FOR(a,a1,a2){
            while(was < a && was<=b2 && win(a,was)) was++;  
            r+=was-b1;
        }
        was=a1;
        FOR(b,b1,b2){
            while(was < b && was<=a2 && win(b,was)) was++;            
            r+=was-a1;
        }

        printf("Case #%d: %lld\n",zz+1,r);
    }
    return 0;
}
