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
    set<char> C;
    for (char c : S) {
        C.insert(c);
    }
    if (S.size() == C.size()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}