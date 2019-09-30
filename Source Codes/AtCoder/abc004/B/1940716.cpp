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
    string s0;
    string s1;
    string s2;
    string s3;
    std::getline(cin, s0);
    std::getline(cin, s1);
    std::getline(cin, s2);
    std::getline(cin, s3);
    reverse(s0.begin(), s0.end());
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());
    cout << s3 << endl;
    cout << s2 << endl;
    cout << s1 << endl;
    cout << s0 << endl;
    return 0;
}