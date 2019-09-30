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
    int ab, bc, ca;
    cin >> ab;
    cin >> bc;
    cin >> ca;

    // ??????   
    auto s = (ab + bc + ca) / 2;
    auto ans = sqrt(s * (s - ab) * (s - bc) * (s - ca));

    cout << ans << endl; 

    return 0;
}