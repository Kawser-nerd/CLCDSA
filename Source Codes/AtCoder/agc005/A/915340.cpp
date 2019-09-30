// TEMPLATES -----------------------------------------------------------------------------------------------------------

#include <vector>
#include <list>
#include <map>
#include <set>
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

using namespace std;

// types
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

// utils
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

// constants
const int INF = INT_MAX / 3;


// MAIN ----------------------------------------------------------------------------------------------------------------


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    // while (cin >> a) {}

    stack<char> s;

    for (auto c : str) {
        if (c == 'S') {
            s.push(c);
        } else {
            if (!s.empty() && s.top() == 'S') {
                s.pop();
            } else {
                s.push(c);
            }
        }
    }

    cout << s.size() << endl;

    return 0;
}