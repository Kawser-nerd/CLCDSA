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

const int N = 107, L = 107;

double pr[N][L];
double dp[N][L];

int next_pos[L][L];
int max_dp[N][L];

void solve(int test_id) {
    int k, l, s;
    cin >> k >> l >> s;
    double coef = 1.0 / k;
    string alpha, target;
    cin >> alpha >> target;
    CLEAR(next_pos);
    for (int i = 0; i < target.size(); ++i) {
        string sub = target.substr(0, i);
        sub += '*';
        for (char c = 'A'; c <= 'Z'; ++c) {
            for (int length = i + 1; length >= 1; --length) {
                sub[i] = c;
                if (sub.substr(i + 1 - length, length) == target.substr(0, length)) {
                    next_pos[i][c - 'A'] = length;
                    break;
                }
            }
        }
    }
    int back_pos = (int) target.size() - 1;
    while (back_pos > 0 && target.substr(0, back_pos) != target.substr(target.size() - back_pos, back_pos)) {
        --back_pos;
    }
    // cout << "BACK_POS IS " << back_pos << endl;
    CLEAR(dp); CLEAR(pr); FILL(max_dp, -1);
    pr[0][0] = 1.0;
    max_dp[0][0] = 0;
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < l; ++j) {
            for (int c = 0; c < alpha.size(); ++c) {
                int np = next_pos[j][alpha[c] - 'A'];
                if (np != target.size()) {
                    pr[i + 1][np] += coef * pr[i][j];
                    dp[i + 1][np] += coef * dp[i][j];
                    max_dp[i + 1][np] = max(max_dp[i + 1][np], max_dp[i][j]);
                } else {
                    np = back_pos;
                    pr[i + 1][np] += coef * pr[i][j];
                    dp[i + 1][np] += coef * (dp[i][j] + 1.0 * pr[i][j]);
                    if (max_dp[i][j] >= 0) {
                        max_dp[i + 1][np] = max(max_dp[i + 1][np], max_dp[i][j] + 1);
                    }
                }
            }
        }
    }

    double answer = 0.0;
    for (int i = 0; i < l; ++i) {
        answer = max(answer, (double) max_dp[s][i]);
    }
    for (int i = 0; i < l; ++i) {
        answer -= dp[s][i];
    }

    cout << "Case #" << test_id << ": ";
    printf("%.10f\n", answer);
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int test_id = 1; test_id <= test_cases; ++test_id) {
        solve(test_id);
    }
    return 0;
}