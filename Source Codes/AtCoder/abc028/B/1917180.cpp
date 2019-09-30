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
    string s;
    cin >> s;

    cout << std::count(s.begin(), s.end(), 'A') << " ";
    cout << std::count(s.begin(), s.end(), 'B') << " ";
    cout << std::count(s.begin(), s.end(), 'C') << " ";
    cout << std::count(s.begin(), s.end(), 'D') << " ";
    cout << std::count(s.begin(), s.end(), 'E') << " ";
    cout << std::count(s.begin(), s.end(), 'F') << endl;
    return 0;
}