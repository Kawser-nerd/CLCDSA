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


bool is_even(const string& s) {
    if (s.size() % 2 != 0) {
        return false;
    }
    int ss = s.size() / 2;
    return s.substr(0, ss) == s.substr(ss, ss);
}

int main() {
    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (is_even(s.substr(0, i))) {
            cout << i << endl;
            return 0;
        }
    }
}