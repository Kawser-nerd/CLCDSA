#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

typedef vector<int> V;

int N;
V card;
vector<V> arr;  // up to 1430 states

void printvi(V &vi) {
    cout<<"#";
    REP(i, SZ(vi)) cout<<" "<<vi[i];
    cout<<endl;
}

map<V, int> memo[10];
int cost(V &vi) {
    if (memo[N].count(vi)) return memo[N][vi];
    REP(i, N) if (vi[i] == 0) return 0;

    bool valid=false;
    FORIT(it, arr) {
        bool hoge=true;
        REP(i, N) if (vi[i] != -1 && vi[i]!=(*it)[i]) { hoge=false; break; }
        if (hoge) { valid=true; break; }
    }
    if (!valid) return 666;

    /*
    REP(i, N) if (vi[i]>=0) {
        FOR(j, i+1, N) if (vi[j]>=0) {
            FOR(k, j+1, N) if (vi[k]>=0) {
                if (vi[i] > vi[j] && vi[j] > vi[k]) return 666; // invalid
            }
        }
    }
    */


    int used[N]; MEMSET(used, 0);
    REP(i, N) if (vi[i] >= 0) { used[vi[i]]=1; }

        // min_x max_z M(T_x,z)
    int res=666;
    REP(x, N) if (vi[x] == -1) {
        int cur=0;
        REP(z, N) if (!used[z]) {
            vector<int> next = vi;
            next[x] = z;
            int c=cost(next);
            if (c >= 666) continue;
            cur = max(cur, 1+c);
        }
        res = min(res, cur);
    }

    //printvi(vi);
    //cout<<"  ==>"<<res<<endl;

    return memo[N][vi] = res;
}

void solve() {
    cin>>N;
    card = V(N);
    REP(i, N) { cin>>card[i]; card[i]--; } // 0-indexed

    V perm(N, 0);
    REP(i, N) perm[i] = i;

    arr.clear();
    do {
            // check
        bool valid=true;
        REP(i, N) FOR(j, i+1, N) FOR(k, j+1, N) {
            if (perm[i] > perm[j] && perm[j] > perm[k]) valid = false;
        }
        if (valid) arr.push_back(perm);

    } while (next_permutation(perm.begin(), perm.end()));

    // cout<<SZ(arr)<<endl;

    // memo.clear();

        // find the best adversary
    V res(N, -666);
    FORIT(it, arr) {
        V adv = *it; // adversary

            // determine this is an enough adversary or not
        V state(N, -1);
        bool valid = true;

        REP(i, N) {
            if (cost(state) != N-i) { valid=false; break; }
            state[card[i]] = adv[card[i]];
        }

        if (valid) res = max(res, adv);
    }

    REP(i, N) printf(" %d", res[i]+1); // 1-indexed
    puts("");
}

int main() {
    int total; cin>>total;
    for (int test=1; test<=total; test++) {
        printf("Case #%d:", test);
        solve();
    }
}
