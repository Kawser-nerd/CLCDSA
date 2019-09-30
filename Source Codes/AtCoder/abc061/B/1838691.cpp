#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        c[a - 1]++;
        c[b - 1]++;
    }

    for (int i = 0; i < n; i++) {
        cout << c[i] << endl;
    }

    return 0;
}