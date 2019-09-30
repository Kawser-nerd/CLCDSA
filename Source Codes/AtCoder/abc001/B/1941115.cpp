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
    int m;
    cin >> m;

    int vv = -1;
    if(m < 100){
        vv = 0;
    }else if(100 <= m && m <= 5000){
        vv = (m / 100);
    }else if(6000 <= m && m <= 30000){
        vv = (m / 1000) + 50;
    }else if(35000 <= m && m <= 70000){
        vv = ((m / 1000) - 30) / 5 + 80;
    }else if(m > 70000){
        vv = 89;
    }

    cout << setw(2) << std::setfill('0') << vv << endl;

    return 0;
}