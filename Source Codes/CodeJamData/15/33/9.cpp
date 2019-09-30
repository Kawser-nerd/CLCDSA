#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define REPR(i, n) for (int i = (n - 1); i >= 0; --i)

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<LL,LL> PLL;

LL go(LL current, LL next, LL max_times) {
    return current + next * max_times;
}

void solve(int test_id) {
    int c, d, v;
    cin >> c >> d >> v;
    vector<LL> coins;
    coins.resize(d);
    REP(i, d) cin >> coins[i];
    SORT(coins);
    int answer = 0;
    LL last = 0;
    for (int i = 0; i < coins.size() && last < v; ++i) {
        if (coins[i] > last + 1) {
            ++answer;
            last = go(last, last + 1, c);
            --i;
        } else {
            last = go(last, coins[i], c);
        }
    }
    while (last < v) {
        ++answer;
        last = go(last, last + 1, c);
    }
    cout << "Case #" << test_id << ": " << answer << endl;
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int test_id = 1; test_id <= test_cases; ++test_id) {
        solve(test_id);
    }
    return 0;
}