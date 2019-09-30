#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

typedef map<string, int> MSI;

const int MOD = 10009;

int N, K, word[100][26];

void Advance(MSI& f0, MSI& f1) {
    f1.clear();
    for (int wid = 0; wid < N; ++wid) {
        int* w = word[wid];
        for (MSI::iterator it = f0.begin(); it != f0.end(); ++it) {
            string const& t = it->first;
            int v = it->second;
            for (int k = 0; k < (1 << t.size()); ++k) {
                string tt;
                int vv = v;
                for (int i = 0; i < t.size(); ++i)
                    if (k >> i & 1)
                        tt += t[i];
                    else
                        vv = vv * w[t[i] - 'a'] % MOD;
                (f1[tt] += vv) %= MOD;
            }
        }
    }
}

string solve() {
    MSI f0, f1;
    {
        string expr;
        cin >> expr;
        int p;
        while ((p = expr.find("+")) != string::npos) expr[p] = ' ';
        istringstream in(expr);
        string t;
        while (in >> t) f0[t] += 1;
    }
    cin >> K >> N;
    for (int i = 0; i < N; ++i) {
        int* w = word[i];
        string wrd;
        cin >> wrd;
        fill(w, w + 26, 0);
        for (int j = 0; j < wrd.size(); ++j)
            if ('a' <= wrd[j] && wrd[j] <= 'z')
                w[wrd[j] - 'a'] += 1;
    }
    ostringstream ret;
    for (int i = 1; i <= K; ++i) {
        Advance(f0, f1);
        if (i > 1) ret << ' ';
        ret << f1[string()];
        f0 = f1;
    }
    return ret.str();
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        freopen((string(argv[1]) + ".in").c_str(), "r", stdin);
        freopen((string(argv[1]) + ".out").c_str(), "w", stdout);
    }
    int cc = 0, ccc = 0;
    for (cin >> ccc; cc < ccc; ++cc)
            cout << "Case #" << cc + 1 << ": " << solve() << endl;
    return 0;
}
