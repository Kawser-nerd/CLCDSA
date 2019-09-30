#include <algorithm>
#include <cctype>
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
    ll a, b, x;
    cin >> a >> b >> x;

    ll aa = (a - a % x) + (a % x == 0 ? 0 : x);
    ll bb = b - b % x;

    if(aa <= bb){
        cout << 1 + (bb - aa) / x << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}