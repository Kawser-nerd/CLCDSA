#include <algorithm>
#include <cctype>
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

const int MOD = 1e9 + 7;

int main(void) {
    int n;
    cin >> n;


    long p = 1;
    for(int i = 1; i <= n; i++){
        p *= i;
        p %= MOD;
    }

    cout << p << endl;
    return 0;
}