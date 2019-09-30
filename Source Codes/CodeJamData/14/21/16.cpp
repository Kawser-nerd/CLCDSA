#include <iostream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <string>
#include <deque>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#include <algorithm>
#include <numeric>

#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define sqr(x) ((x) * (x))
#define len(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'

#ifdef CUTEBMAING
#include "cutedebug.h"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(x) 42
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef unsigned long long lint;
typedef long double ld;

const int inf = ((1 << 30) - 1);
const int64 linf = ((1ll << 62) - 1);

void solve(){
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string b = a[0];
    b.resize(unique(all(b)) - b.begin());
    for (int i = 0; i < n; i++){
        string c = a[i];
        c.resize(unique(all(c)) - c.begin());
        if (b != c){
            cout << "Fegla Won" << endl;
            return ;
        }
    }
    vector<vector<int> > c(n);
    for (int i = 0; i < n; i++){
        string cur = a[i];
        for (int j = 0; j < len(cur); ){
            int it = j;
            while (it < len(cur) && cur[it] == cur[j])
                it++;
            c[i].pb(it - j);
            j = it;
        }
    }
    int ans = 0;
    for (int i = 0; i < len(c[0]); i++){
        vector<int> cur;
        for (int j = 0; j < n; j++)
            cur.pb(c[j][i]);
        nth_element(cur.begin(), cur.begin() + len(cur) / 2, cur.end());
        int point = cur[len(cur) / 2];
        for (int j = 0; j < n; j++)
            ans += abs(c[j][i] - point);
    }
    printf("%d\n", ans);
}

int main(){
#if defined CUTEBMAING && !defined STRESS
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif
    int testCasesCount = 0;
    cin >> testCasesCount;
    for (int i = 1; i <= testCasesCount; i++){
        printf("Case #%d: ", i);
        double begin = clock();
        solve();
        double end = clock();
        eprintf("Test %d: %.3lf seconds\n", i, (end - begin) / CLOCKS_PER_SEC);
    }
    return 0;
}
