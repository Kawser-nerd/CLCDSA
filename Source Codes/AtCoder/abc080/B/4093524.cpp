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

int main() {
    ull N;
    cin >> N;
    string S = to_string(N);
    ull Fx = 0;
    for (char c : S) {
        Fx += c - '0';
    }
    if (N % Fx == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}