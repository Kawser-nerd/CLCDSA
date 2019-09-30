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

int solve(int a, int b, int c){
    if(a > b && a > c){
        return 1;
    }else if(a < b && a < c){
        return 3;
    }else{
        return 2;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c) << endl;
    cout << solve(b, c, a) << endl;
    cout << solve(c, a, b) << endl;

    return 0;
}