#include <map>
#include <iostream>
#include <deque>
#include <list>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOREACH(i,c) for(__typeof((c).begin()) i =(c).begin();i!=(c).end();++i)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef long double LD;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int NIL = (-1);

LL bp(LL a, LL d, LL p) {
    if (d==0) return 1;
    if (d%2==1) return (a*bp(a,d-1,p))%p;
    LL t = bp(a,d/2,p);
    return (t*t)%p;
}

LL rev(LL a, LL p) { return bp(a,p-2,p); }

LL p10[] = {1,10,100,1000,10000,100000,1000000};

const int N = 1<<20;
bool s[N];

void situj() {
    REP(i,N) s[i] = 1;
    s[0] = s[1] = 0;
    for(int i=2;i<N;i++) if (s[i]) {
        for(int j=2*i;j<N;j+=i) s[j] = false;
    }
}

int d,k;
LL a[30];

void idk() { printf("I don't know.\n"); }

LL solve(LL p) {
//    printf("solve %lld\n",p);
    LL A = ((a[1]-a[2])*rev(a[0]-a[1],p))%p;
    A = (A+p)%p;
    LL B = a[1] - A*a[0];
    B %= p;
    B = (B+p)%p;
  //  printf("A = %lld B = %lld\n",A,B);
    for(int i=1;i<k;i++)
        if (a[i] != ((a[i-1]*A+B)%p)) return (-1);
    //printf("hurra\n");
    return (A*a[k-1]+B)%p;
}

void scase() {
    
    scanf("%d%d",&d,&k);
    REP(i,k) scanf("%lld",&a[i]);

    if (k<=1) {
        idk();
        return;
    }
    
    if(a[k-1] == a[k-2]) {
        printf("%lld\n",a[k-1]);
        return;
    }

    if (k==2) { //(?)
        idk();
        return;
    }

    LL sol = -1;
    
    LL m = 0;
    REP(i,k) m = max(m,a[i]);

    for(int i = m+1; i<p10[d]; i++) if (s[i]) {
        LL x = solve(i);
        if (x!=NIL) {
            if (sol==NIL) {
                sol = x;
            } else {
                if (sol!=x) {
                    idk();
                    return;
                }
            }
        }
    }
    printf("%lld\n",sol);


}

int main() {
    situj();
    int j;
    scanf("%d",&j);
    for(int i=1;i<=j;i++) {
        printf("Case #%d: ",i);
        scase();
    }
    return 0;
}

