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

int n,m,k;

void readTest(){
    scanf("%d%d%d",&n,&m,&k);
}

int sum;
int score;
int level;

int _run(int len, int d){
    if (sum+len >= k)
        return (score+len);
    if (level == n-1)
        return k;
    sum += len;
    int oldScore = score;
    if (level == 0)
        score += len;
    else
        score += (len == 1)?1:2;
    level++;
    int best = k;
    if (d == 1){
        if (len+1 <= m)
            best = min(best,_run(len+1,1));
        if (len+2 <= m)
            best = min(best,_run(len+2,1));
    }
    if (d >= 0)
        best = min(best,_run(len,0));
    if (len >= 2)
        best = min(best,_run(len-1,-1));
    if (len >= 3)    
        best = min(best,_run(len-2,-1));
    level--;
    score = oldScore;
    sum -= len;
    return best;
}

int run(int start){
    sum = 0;
    level = 0;
    score = 0;
    return _run(start,1);
}

void solveTest(int t){
    if (n > m) swap(n,m);
    int best = k;
    FOR(i,1,m+1)
        best = min(best,run(i));
    printf("Case #%d:",t);
    printf(" %d",best);
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
