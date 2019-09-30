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
    int A, B, C;
    cin >> A >> B >> C;
    bool add = (A + B) == C;
    bool sub = (A - B) == C;
    if (add && sub) {
        cout << "?" << endl;
    } else if (add) {
        cout << "+" << endl;
    } else if (sub) {
        cout << "-" << endl;
    } else {
        cout << "!" << endl;
    }
}