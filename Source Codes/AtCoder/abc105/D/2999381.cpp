#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
 
long long factorial(long long n) {
    long long result = 1;
    for (long long i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
 
long long combination(long long n, long long r) {
    long long result = factorial(n) / factorial(n - r) / factorial(r);
    // cout << "combination " << n << " C " << r << "is " << result << endl;
    return result;
}
 
long long combination_improved(long long n, long long r) {
    long long d      = n - r;
    long long result = 1;
    while (n > 1 || d > 1 || r > 1) {
        if (n > 1) {
            result *= n;
            n--;
        }
        if (d > 1 && result % d == 0) {
            result /= d;
            d--;
        }
        if (r > 1 && result % r == 0) {
            result /= r;
            r--;
        }
    }
    // cout << "combination " << n << " C " << r << "is " << result << endl;
    return result;
}
 
int main(void) {
    // cout << std::fixed << std::setprecision(10);
    // cin.tie(0);
    // std::ios::sync_with_stdio(false);
    long long n, m;
    long long count=0;
    long long cum[100001];
    std::multimap<long long, long long> mod_map; //(mod M,number)
    cin >> n >> m;
    long long m1;
    for (int i = 0; i < n; i++) {
        cin >> m1;
        if (i == 0)
            cum[i] = m1;
        else
            cum[i] = cum[i - 1] + m1;
    }
    for (int i = 0; i < n; i++) {
        mod_map.insert(std::make_pair(cum[i] % m, cum[i]));
    }
 
    int prev = m;
    for (auto itr : mod_map) {
        // cout << itr.first << " " << itr.second << endl;
        if (prev != itr.first) {
            if (itr.first == 0) {
                if (mod_map.count(0) >= 1)
                    count += combination_improved(mod_map.count(0) + 1, 2);
            } else {
                if (mod_map.count(itr.first) >= 2) {
                    count += combination_improved(mod_map.count(itr.first), 2);
                }
            }
        }
        prev = itr.first;
    }
 
    cout << count << endl;
 
    return 0;
}