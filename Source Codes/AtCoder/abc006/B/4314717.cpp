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
ull e = 10007;
const double pi = 3.14159265359;

map<int, int> a;

int calc(int n) {
    if (a.count(n)) return a[n];
    return a[n] = ((((calc(n - 1) % e) + (calc(n - 2) % e)) % e) + (calc(n - 3) % e)) % e;
}

int main() {
    a[1] = 0;
    a[2] = 0;
    a[3] = 1;
    int n;
    cin >> n;
    cout << calc(n) << endl;
}