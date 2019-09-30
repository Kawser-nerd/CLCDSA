#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <stdbool.h>
#include <bitset>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;


int main(void) {
    int n,k;
    cin >> n;
    cin >> k;
    k -= 1;

    vector<mp::cpp_int> trees(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end());
    // ??????????
    // ????????k????????hmax-hmin?????????
    mp::cpp_int min = 9999999999999999;
    for(int i = 0 ; i < n - k ; ++i) {
        auto d = abs(trees[i] - trees[i + k]);
        if (d < min) {
            min = d;
        }
    }
    cout << min << endl;
    return 0;
}