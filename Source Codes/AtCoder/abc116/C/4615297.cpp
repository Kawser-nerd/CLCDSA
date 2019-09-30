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

int mizuyari(vector<int> h) {
    // 0???????????????
    // for(const auto& x : h) {
    //     cout << x << ", ";
    // }
    // cout << endl;

    int count = 0;
    for(int i = 0 ; i < h.size() ; ) {
        if (!h[i]) {
            i++;
            continue;
        }
        vector<int> sub; // ??????vector
        int j;
        for(j = i ; j < h.size() ; ++j ) {
            if(!h[j]) {
                break;
            } else {
                sub.push_back(h[j] - 1); // ?????
            }
        }
        // (i, j]??????
        count++; // ???????
        count += mizuyari(sub); // ??????????????
        // ???
        i = j;
    }
    return count;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> h[i];
    }
    auto ans = mizuyari(h);
    cout << ans << endl;
    return 0;
}