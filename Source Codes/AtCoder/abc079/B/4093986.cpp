#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

map<ull, ull> table;

ull lucas(ull n) {
    if (table.count(n)) {
        return table[n];
    } else {
        return table[n] = lucas(n - 1) + lucas(n - 2);
    }
}

int main() {
    table[0] = 2;
    table[1] = 1;
    ull N;
    cin >> N;
    cout << lucas(N) << endl;
}