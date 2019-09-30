#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <fstream>
#include <set>

#define FOR(i,a,b)  for(__typeof(b) i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define FOREACH(x,c)   for(__typeof(c.begin()) x=c.begin();x != c.end(); x++)
#define ALL(c)      c.begin(),c.end()
#define CLEAR(c)    memset(c,0,sizeof(c))
#define SIZE(c) (int) ((c).size())

#define PB          push_back
#define MP          make_pair
#define X           first
#define Y           second

#define ULL         unsigned long long
#define LL          long long
#define LD          long double
#define II         pair<int, int>
#define DD         pair<double, double>

#define VC	    vector
#define VI          VC<int>
#define VVI         VC<VI>
#define VD          VC<double>
#define VS          VC<string>
#define VII         VC<II>
#define VDD         VC<DD>

#define DB(a)       cerr << #a << ": " << a << endl;

using namespace std;

template<class T> void print(VC < T > v) {cerr << "[";if (SIZE(v) != 0) cerr << v[0]; FOR(i, 1, SIZE(v)) cerr << "," << v[i]; cerr << "]\n";}
template<class T> string i2s(T &x) { ostringstream o; o << x; return o.str(); }
VS split(string &s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < SIZE(s)) all.PB(s.substr(p)); return all;}

ULL p,q;

ULL gcd(ULL a, ULL b){
    if (a < b) swap(a,b);
    while(b != 0){
        ULL c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void readTest(){
    scanf("%llu/%llu",&p,&q);
}

int power2(ULL x){
    while (x != 1){
        if (x%2 == 1)
            return 0;
        else
            x /= 2;
    }
    return 1;
}

void solveTest(int t){
    ULL d = gcd(p,q);
    p /= d;
    q /= d;
    if (!power2(q)){
        printf("Case #%d: impossible\n",t);
        return;
    }
    int res = 0;
    while (p < q){
        q /= 2;
        res++;
    } 
    printf("Case #%d:",t);
    printf(" %d",res);
    printf("\n");
}

int main(int argc, char *argv[]){
    int T;
    scanf("%d",&T);
    REP(t,T){
        readTest();
        solveTest(t+1);
    }
    return 0;
}
