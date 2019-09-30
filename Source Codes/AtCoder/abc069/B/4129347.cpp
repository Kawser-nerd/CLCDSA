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
    cout << S[0] << S.size() - 2 << S[S.size() - 1] << endl;
}