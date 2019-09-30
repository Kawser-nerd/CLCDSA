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
    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    bool ans = h1 == h2 || h1 == w2 || w1 == h2 || w1 == w2;
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}