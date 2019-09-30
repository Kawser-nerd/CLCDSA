#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

class hint {
   public:
    string v;
    string w;
    hint() {}
    hint(string v, string w) : v(v), w(w) {}
};

vector<string> eval(const vector<hint>& hs, int n, int k, vector<int>& ls) {
    vector<string> assign(k);

    for (const hint& h : hs) {
        const string& v = h.v;
        const string& w = h.w;

        size_t wp = 0;
        for (char d : v) {
            int di = d - '0';
            if (assign[di] == "") {
                for (int i = 0; i < ls[di]; i++) {
                    if (wp >= w.length()) {
                        return vector<string>();
                    }
                    assign[di].push_back(w[wp++]);
                }
            } else {
                for (int i = 0; i < ls[di]; i++) {
                    if (wp >= w.length() || assign[di][i] != w[wp++]) {
                        return vector<string>();
                    }
                }
            }
        }
        if(wp != w.length()){
            return vector<string>();
        }
    }

    return assign;
}

vector<string> backtrack(const vector<hint>& hs, int n, int k, int d,
                         vector<int>& ls) {
    if (d >= k) {
        return eval(hs, n, k, ls);
    }

    for (int i = 1; i <= 3; i++) {
        ls[d] = i;
        vector<string> ans = backtrack(hs, n, k, d + 1, ls);
        if (ans.size() > 0) {
            return ans;
        }
    }
    return vector<string>();
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<hint> hs(n);
    for (int i = 0; i < n; i++) {
        cin >> hs[i].v >> hs[i].w;
        for (size_t j = 0; j < hs[i].v.size(); j++) {
            hs[i].v[j]--;
        }
    }

    vector<int> ls(k);
    vector<string> ans = backtrack(hs, n, k, 0, ls);

    for (int i = 0; i < k; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}