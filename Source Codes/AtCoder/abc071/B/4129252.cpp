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

int main() {
    string S;
    cin >> S;
    set<char> m;
    for (char c : S) {
        m.insert(c);
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (m.count(c) == 0) {
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}