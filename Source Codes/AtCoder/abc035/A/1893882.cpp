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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int w, h;
    cin >> w >> h;

    int g = gcd(w, h);
    w /= g;
    h /= g;
    int ww = max(w, h);
    int hh = min(w, h);
    if (ww == 16 && hh == 9) {
        cout << "16:9" << endl;
    }
    if (ww == 4 && hh == 3) {
        cout << "4:3" << endl;
    }

    return 0;
}