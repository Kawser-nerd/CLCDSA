#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <cctype>

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
    char c, d;
    cin >> c >> d;
    cout << (tolower(c) == tolower(d) ? "Yes" : "No") << endl;
    return 0;
}