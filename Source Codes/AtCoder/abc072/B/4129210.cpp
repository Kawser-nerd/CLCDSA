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
    for (int i = 0; i < S.size(); i += 2) {
        cout << S[i];
    }
    cout << endl;
}