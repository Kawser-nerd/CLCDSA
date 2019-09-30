#include <cstdio>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void solve(int case_num) {
    long long n, p;
    cin >> n >> p;
    --p;
    cerr << p << endl;
    int num_0 = 0;
    for (int i = n - 1; i >= 0; --i) {
        long long y = 1;
        for (int j = 0; j < i; ++j) y *= 2;
        if (p & y) {
            if ((p + 1) & y) ++num_0; // We have to win one more time
            break; 
         } else ++num_0;
    }
    int num_1 = 0;
    for (int i = n - 1; i >= 0; --i) {
        long long y = 1;
        for (int j = 0; j < i; ++j) y *= 2;
        if (p & y) ++num_1; else break;
    }
    
    long long y = 1;
    for (int i = 0; i < n; ++i) y *= 2;
    
    cerr << num_0 << num_1 << endl;
    long long worst_case = 0;
    if (p + 1 == y) worst_case = p; else 
    for (int i = 0; i < num_1; ++i) worst_case = worst_case * 2 + 2;
    long long best_case = 0;
    for (int i = 0; i < num_0; ++i) best_case = best_case * 2 + 1;
    best_case = y - best_case - 1;
    cout << "Case #" << case_num << ": " << worst_case << " " << best_case << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve(i + 1);
}

