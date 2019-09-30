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
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'B') {
            s[i] = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (s[j] != 0) {
                    s[j] = 0;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 0) continue;
        cout << s[i];
    }
    cout << endl;
}