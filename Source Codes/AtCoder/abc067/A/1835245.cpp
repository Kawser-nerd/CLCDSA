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
    int a, b;
    cin >> a >> b;
    bool ans = (a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0);
    cout << (ans ? "Possible" : "Impossible") << endl;
    return 0;
}