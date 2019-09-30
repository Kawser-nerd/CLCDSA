#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;


int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n - 1 << endl;
    } else {
        cout << n + 1 << endl;
    }
}