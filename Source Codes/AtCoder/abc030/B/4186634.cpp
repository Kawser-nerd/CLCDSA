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


int main() {
    int n, m;
    cin >> n >> m;
    double H = 360 * ((n % 12) / 12.0 + m / 720.0);
    double M = 360 * (m / 60.0);
    double C = abs(H - M);
    cout << min(C, (360.0 - C)) << endl;
}