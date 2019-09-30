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
    int N;
    cin >> N;

    int min_ = 99999, max_ = -1;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        min_ = min(min_, tmp);
        max_ = max(max_, tmp);
    }
    cout << max_ - min_ << endl;
}