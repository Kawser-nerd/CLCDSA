#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define INIT(a, v) __typeof(v) a = (v)
#define FOREACH(a, v) for (INIT(a, (v).begin()); a!=(v).end(); ++a)
 
template<class T>
inline int size(const T&t){return t.size();}
 
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long LL;

#define INF 1000000000
#define PB push_back
#define MP make_pair
 
//////////////////////////////////////////

LL N;
int pd, pc;

int nwd(int a, int b) {
    return !b ? a : nwd(b, a%b);
}

bool check() {
    if (pd<100 && pc==100)
        return false;
    if (pd>0 && pc==0)
        return false;
    int w1 = 100/nwd(100, pd);
    int w2 = nwd(pc, 100);
    w2 = w2/nwd(w2, abs(pc-pd));
    int ww = w1*w2/nwd(w1, w2);
    return ww<=N;
}

int main() {
    int TT;
    scanf("%d", &TT);
    REP(tt, TT) {
        scanf("%Ld%d%d", &N, &pd, &pc);
        printf("Case #%d: %s\n", (tt+1), check() ? "Possible" : "Broken");
    }
}


