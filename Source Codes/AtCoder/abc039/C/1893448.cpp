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

int main() {
    vector<string> table = {"Do",  "Do#", "Re",  "Re#", "Mi",  "Fa",
                            "Fa#", "So",  "#So", "La",  "#La", "Si"};
    string s;
    cin >> s;

    int n = s.length();
    int p0 = -1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            p0 = i;
            break;
        }
    }

    int p1 = -1;
    for (int i = p0 + 1; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            p1 = i;
            break;
        }
    }

    int j = (p1 - p0 == 7) ? 4 /*Mi*/ : 11 /*Si*/;
    for (int k = 0; k < p0; k++) {
        j = (j - 1 + table.size()) % table.size();
    }
    cout << table[j] << endl;

    return 0;
}