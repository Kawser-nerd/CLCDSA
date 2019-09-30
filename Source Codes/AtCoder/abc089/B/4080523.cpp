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
    int N;
    set<char> S;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char s;
        cin >> s;
        S.insert(s);
    }
    if (S.size() == 3) {
        cout << "Three" << endl;
    } else {
        cout << "Four" << endl;
    }
}