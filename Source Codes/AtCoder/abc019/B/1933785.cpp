#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
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
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int cnt = -1;
    for (int i = 0; i < n; i += cnt) {
        cnt = 0;
        for(int j = i; j < n && s[j] == s[i]; j++){
            cnt++;
        }
        cout << s[i] << cnt;
    }
    cout << endl;

    return 0;
}