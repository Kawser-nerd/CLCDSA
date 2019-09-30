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
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

string winner(string s) {
    if (s.find('.') == string::npos && s.find('X') == string::npos) {
        return "O won";
    }
    if (s.find('.') == string::npos && s.find('O') == string::npos) {
        return "X won";
    }
    return "";
}

string alg() {
    vector<string> board(4);
    for (int i = 0; i < 4; ++i) {
        cin >> board[i];
    }
    bool full = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            full &= (board[i][j] != '.');
        }
    }
    for (int i = 0; i < 4; ++i) {
        string s = winner(board[i]);
        if (!s.empty()) {
            return s;
        }
        string c = "";
        for (int j = 0; j < 4; ++j) {
            c += board[j][i];
        }
        s = winner(c);
        if (!s.empty()) {
            return s;
        }
    }
    {
        string c = "";
        for (int i = 0; i < 4; ++i) {
            c += board[i][i];
        }
        string s = winner(c);
        if (!s.empty()) {
            return s;
        }
    }
    {
        string c = "";
        for (int i = 0; i < 4; ++i) {
            c += board[i][3 - i];
        }
        string s = winner(c);
        if (!s.empty()) {
            return s;
        }
    }
    if (!full) {
        return "Game has not completed";
    }
    return "Draw";
}

int main() {
    ios_base::sync_with_stdio(false);
    int n_cases;
    cin >> n_cases;
    for (int test_case = 1; test_case <= n_cases; ++test_case) {
        cout << "Case #" << test_case << ": " << alg() << endl;
    }
}
