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
    string s, t;
    cin >> s >> t;

    vector<char> sv, tv;
    for (char c : s) {
        sv.push_back(c);
    }
    for (char c : t) {
        tv.push_back(c);
    }
    sort(sv.begin(), sv.end());
    sort(tv.rbegin(), tv.rend());

    string s_ = "", t_ = "";
    for (char c : sv) {
        s_ += c;
    }
    for (char c : tv) {
        t_ += c;
    }
    if (s_ < t_) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}