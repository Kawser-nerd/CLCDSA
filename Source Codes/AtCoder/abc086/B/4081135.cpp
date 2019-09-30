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
    int a, b;
    cin >> a >> b;
    int ab = stoi(to_string(a) + to_string(b));
    bool ans = false;
    for (int i = 1; i < 317; ++i) {
        int tmp = i * i;
        if (tmp > ab) break;
        if (tmp == ab) {
            ans = true;
            break;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}