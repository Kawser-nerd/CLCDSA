#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 26 + 8;

// o -> 0
// i -> 1
// e -> 3
// a -> 4
// s -> 5
// t -> 7
// b -> 8
// g -> 9

const string changeable = "oieastbg";

map<char, vector<int> > possible;

bool e[N][N];

void alg() {
    int k;
    cin >> k;
    ZERO(e);
    string s;
    cin >> s;
    for (int i = 0; i + 1 < (int) s.size(); ++i) {
        FORE (it, possible[s[i]]) {
            FORE (jt, possible[s[i + 1]]) {
                e[*it][*jt] = true;
            }
        }
    }
    int added = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int dif = 0;
        for (int j = 0; j < N; ++j) {
            if (e[i][j]) {
                ++sum;
                ++dif;
            }
            if (e[j][i]) {
                --dif;
            }
        }
        added += abs(dif);
    }
    static int case_no = 0;
    cout << "Case #" << ++case_no << ": " << sum + added / 2 + bool(added == 0) << endl;
}

int main() {
    for (int i = 'a'; i <= 'z'; ++i) {
        possible[i].PB(i - 'a');
    }
    FORE (it, changeable) {
        possible[*it].PB(26 + (int) (it - changeable.begin()));
    }
    int d;
    cin >> d;
    while (d--) {
        alg();
    }
}
