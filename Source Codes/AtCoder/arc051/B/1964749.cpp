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
    vector<int> as;
    vector<int> bs;
    as.push_back(1);
    bs.push_back(0);

    as.push_back(2);
    bs.push_back(1);
    for (int i = 2; i <= 40; i++) {
        as.push_back(as[i - 1] + bs[i - 1]);
        bs.push_back(as[i - 1]);
    }

    int k;
    cin >> k;
    cout << as[k] << " " << bs[k] << endl;

    return 0;
}