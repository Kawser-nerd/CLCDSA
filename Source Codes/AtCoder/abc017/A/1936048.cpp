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
    int s1, e1;
    int s2, e2;
    int s3, e3;
    cin >> s1 >> e1;
    cin >> s2 >> e2;
    cin >> s3 >> e3;

    cout << (s1 * e1 / 10) + (s2 * e2 / 10) + (s3 * e3 / 10) << endl;

    return 0;
}