#include <iostream>
#include <map>

using namespace std;

int main() {
    long long n;
    map <long long, long long> m;
    long long res = 0;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long s[n+1];
    s[0] = 0;
    for (long long i = 1; i < n + 1; i++) {
        s[i] = s[i-1] + a[i-1];
    }
    for (long long i = 0; i < n + 1; i++) {
        if (m.find(s[i]) != m.end()) {
            m[s[i]] += 1;
        } else {
            m[s[i]] = 1;
        }
    }
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        long long c = itr->second;
        res += c * (c - 1) / 2;
    }
    cout << res << endl;
}