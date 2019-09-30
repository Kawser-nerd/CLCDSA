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

void solve(int test_id) {
    int n, m, k;
    cin >> n >> m >> k;
    int answer = 0;
    if (k == 1) {
        answer = n * m;
    } else {
        answer += n * ((m - k) / k + 1);
        answer += k - 1;
        if (m % k != 0) ++answer;
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