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
    int n;
    cin >> n;
    int d0 = n % 10;
    int d1 = n / 10 % 10;
    int d2 = n / 100 % 10;
    int d3 = n / 1000 % 10;
    bool ans = (d0 == d1) && (d1 == d2) && (d2 == d3);
    cout << (ans ? "SAME" : "DIFFERENT") << endl;
    return 0;
}