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
    ull A, B, C;
    cin >> A >> B >> C;
    cout << (((A % E) * (B % E) % E) * (C % E)) % E << endl;
}