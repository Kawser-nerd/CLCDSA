#include <algorithm>
#include <complex>
#include <iomanip>
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
    int n, a;
    cin >> n >> a;
    a--;

    string k;
    cin >> k;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<int> visited(n, -1);
    int cnt = 0;
    int i = a;
    while (visited[i] == -1) {
        visited[i] = cnt++;
        i = b[i];
    }

    int t = cnt - visited[i];
    int d = visited[i];

    int m = -1;
    if (k.length() <= 7) {
        m = std::stoi(k);
    } else {
        // k % t
        m = 0;
        for (char c : k) {
            m = (10 * m + (c - '0')) % t;
        }

        while (m < d) {
            m += t;
        }
    }

    i = a;
    for (int j = 0; j < m; j++) {
        i = b[i];
    }
    cout << i + 1 << endl;

    return 0;
}