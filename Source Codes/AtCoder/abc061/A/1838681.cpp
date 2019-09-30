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
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a <= c && c <= b ? "Yes" : "No") << endl;
    return 0;
}