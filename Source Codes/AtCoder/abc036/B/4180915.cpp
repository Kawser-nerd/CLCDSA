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

char s[51][51];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = N - 1; j >= 0; --j) {
            cout << s[j][i];
        }
        cout << endl;
    }
}