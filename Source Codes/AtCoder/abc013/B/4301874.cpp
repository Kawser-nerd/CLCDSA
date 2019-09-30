#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;
const double pi = 3.14159265359;

int main() {
    int a, b;
    cin >> a >> b;
    int d1 = abs(a - b);
    int d2 = 10 - d1;
    cout << min (d1, d2) << endl;
}