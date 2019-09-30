#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <set>
#include <tuple>
#include <stdbool.h>
#include <bitset>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    int c0 = count(str.cbegin(), str.cend(), '0');
    int c1 = count(str.cbegin(), str.cend(), '1');
    cout << (2 * (c0 < c1 ? c0 : c1)) << endl;
    return 0;
}