#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int A,N;
int V[105];

map<PII, int> memo;

int go(int pos, int cur) {
    if(pos == N) {
        return 0;
    }

    PII key = mp(pos, cur);
    if(cur > V[pos]) {
        return go(pos+1, cur + V[pos]);
    }

    if(memo.count(key)) return memo[key];

    int ret = N-pos;

    for(int i=1;i<N-pos;i++) {
        cur += (cur - 1);
        if(cur > V[pos]) {
            int tmp = i + go(pos+1, cur + V[pos]);
            if(tmp < ret) ret = tmp;
        }
    }

    return memo[key] = ret;
}

void process(void) {
    memo.clear();
    scanf("%d %d", &A, &N);
    for(int i=0;i<N;i++) scanf("%d", &V[i]);
    sort(V,V+N);

    if(A == 1) {
        cout << N << endl;
        return;
    }

    cout << go(0, A) << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        // cerr << i << endl;
    }
}
