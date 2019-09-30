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
const double pi = 3.14159265359;

int main() {
    string S;
    cin >> S;
    cout << (char)toupper(S[0]);
    for (int i = 1; i < S.size(); ++i) {
        cout << (char)tolower(S[i]);
    }
    cout << endl;
}