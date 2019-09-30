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


int cnt[100];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i< M; ++i) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 1; i <= N; ++i) {
        cout << cnt[i] << endl;
    }
}