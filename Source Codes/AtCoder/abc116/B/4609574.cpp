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

map<int, int> memorize;
int f(int n) {
    if (memorize.count(n)) {
        return memorize[n];
    }
    int x = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    memorize[n] = x;
    return x;
}

int main(void) {
    int s;
    cin >> s;

    int i;
    set<int> ans;
    ans.insert(s);
    for(i = 2; ; ++i) {
        s = f(s);
        if(ans.count(s)) break;
        ans.insert(s);
    }
    cout << i << endl;
    return 0;
}