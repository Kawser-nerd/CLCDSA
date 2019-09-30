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
    string s;
    int k;
    cin >> s;
    cin >> k;
    set<string> S;
    for (int i = 0; i + k <= (int)s.size(); ++i) {
        S.insert(s.substr(i, k));
    }
    cout << S.size() << endl;
}