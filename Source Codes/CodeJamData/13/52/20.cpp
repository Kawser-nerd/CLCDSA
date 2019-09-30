#define debug if(0)
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <climits>
#include <sstream>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR_EACH(it,v) for(__typeof((v).begin()) it = (v).begin(); it!=(v).end(); ++it)
#define show(x) debug cout << #x << ": " << x << endl;

#define ALL(v) (v).begin(), (v).end()

template<typename T>
ostream& operator<<(ostream &o, const vector<T>&v){
    FOR_EACH(x, v){
        if(x==v.begin()) o << "[";
        else o << ", ";
        o << *x;
    }
    o << "]";
    return o;
}

const int inf = 100005;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int>VI;
typedef vector<vector<int> >VII;

struct xy{
    LL x,y;
    explicit xy(int x_ = inf, int y_ = inf):x(x_), y(y_){
    }
    xy operator - (const xy& rh) const {
        return xy(x-rh.x, y-rh.y);
    }
    xy operator + (const xy& rh) const {
        return xy(x+rh.x, y+rh.y);
    }
};

LL det(xy a, xy b, xy c){
    b = b - a;
    c = c - a;
    return b.x * c.y - b.y * c.x;
}

int sgn(LL x){
    if(x<0) return -1;
    if(x==0) return 0;
    return 1;
}

bool int1(xy a, xy b, xy p, xy q){
    int f = sgn(det(a,b,p));
    int g = sgn(det(a,b,q));
    return f*g == -1;
}

bool intersect(xy a, xy b, xy p, xy q){
    return int1(a,b,p,q) && int1(p,q,a,b);
}

const int N = 1333;
xy P[N];
int n;

bool between(int p, int a, int b){
    if(p<min(a,b)) return false;
    if(p>max(a,b)) return false;
    return true;
}

bool between(xy p, xy a, xy b){
    return between(p.x, a.x, b.x) && between(p.y, a.y, b.y);
}

LL compute(const VI& ids){
    REP(i_, n){
        REP(j_, i_){
            int i = ids[i_];
            int i2 = ids[(i_+1)%n];

            int j = ids[j_];
            int j2 = ids[(j_+1)%n];

            if(intersect(P[i], P[i2], P[j], P[j2])) return -1;
        }
    }

    REP(i, n){ //each post
        int cnt = 0;
        REP(a_, n){ //each seg
            int a = ids[a_];
            int b = ids[(a_+1)%n];

            if(!between(P[i], P[a], P[b])) continue;
            if(det(P[i], P[a], P[b])==0) cnt++;
        }
        assert(cnt>=2);
        if(cnt!=2) return -1;
    }

    LL res = 0;
    REP(i_, n){
        const xy &a = P[ids[i_]];
        const xy &b = P[ids[(i_+1)%n]];
        debug printf("%lld %lld\n", a.x, a.y);
        res += (b.x-a.x) * (b.y + a.y);
    }
    return abs(res);
}

void solve(){
    scanf("%d", &n);
    VI ids;
    REP(i,n){
        ids.push_back(i);
        scanf("%lld %lld", &P[i].x, &P[i].y);
    }

    LL best = 0;
    VI ans;
    do {
        LL tmp = compute(ids);
        show(ids);
        show(tmp);
        if(tmp > best){
            ans = ids;
            best = tmp;
        }
    } while(next_permutation(ids.begin()+1, ids.end()));

    FOR_EACH(x, ans) printf("%d ", *x);
    printf("\n");
}

int main(int argc,char *argv[]) {
    int T; scanf("%d", &T);
    for(int t=1; t<=T; t++){
        printf("Case #%d: ", t);
        debug cout << endl;
        solve();
    }
}
