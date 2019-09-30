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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>

#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (signed)((a).size())
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int MOD = 1000000007;

#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;

signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);

    int n;
    cin >> n;
    VS s(n);
    REP(i,n){
        cin >> s[i];
    }

    VVI a(n,VI(26,0));
    REP(i,n){
        REP(j,s[i].length()){
            a[i][s[i][j]-'a']++;
        }
    }

    REP(i,26){
        int t = INT_MAX;
        REP(j,n){
            t=min(t,a[j][i]);
        }
        REP(j,t){
            printf("%c",'a'+i);
        }
    }
    cout << endl;
    return 0;
} ./Main.cpp:72:25: warning: format specifies type 'int' but the argument has type 'long long' [-Wformat]
            printf("%c",'a'+i);
                    ~~  ^~~~~
                    %lld
1 warning generated.