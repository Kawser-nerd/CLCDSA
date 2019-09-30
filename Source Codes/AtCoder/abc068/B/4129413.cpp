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

int table[101];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= 100; ++i) {
        for (int n = i; n > 0 && n % 2 == 0; n /= 2) {
            ++table[i];
        }
    }
    int ans = 0;
    int tmp = -1;
    for (int i = 1; i <= N; ++i) {
        if (table[i] > tmp) {
            tmp = table[i];
            ans = i;
        }
    }
    cout << ans << endl;
}