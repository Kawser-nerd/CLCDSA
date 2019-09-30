#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>

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
    double n, k;
    cin >> n >> k;

    double a = k - 1;
    double b = 1;
    double c = n - k;

    double r = 0;
    r += 6 * a * b * c;
    r += 3 * b * b * a;
    r += 3 * b * b * c;
    r += 1 * b * b * b;

    r /= n * n * n;

    cout << std::fixed << std::setprecision(16);
    cout << r << endl;

    return 0;
}