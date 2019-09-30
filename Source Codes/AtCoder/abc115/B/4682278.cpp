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
    int n;
    cin >> n;

    int sum = 0;
    int max = 0;
    for(int i = 0 ; i < n ; ++i) {
        int p;
        cin >> p;
        sum += p;
        if(max < p) {
            max = p;
        }
    }
    sum -= max / 2;
    cout << sum << endl;
    return 0;
}