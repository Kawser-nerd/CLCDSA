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
    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int ap = 0;
    int bp = 0;
    int cnt = 0;
    int time = 0;
    while (1) {
        // A
        while (ap < n && a[ap] < time) {
            ap++;
        }
        if(ap >= n){
            // no plane
            break;
        }
        time = a[ap];
        time += x;

        // B
        while (bp < m && b[bp] < time) {
            bp++;
        }
        if(bp >= m){
            // no plane
            break;
        }
        time = b[bp];
        time += y;

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}