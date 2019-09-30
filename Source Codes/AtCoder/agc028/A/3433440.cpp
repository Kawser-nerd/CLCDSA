#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}

int main()
{
    long long n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int g = gcd(n, m);
    long long z = n * m / g;

    map<long long, char> mic;
    for (int i = 0; i < n; ++i)
    {
        long long idx = i * (z / n) + 1;
        mic[idx] = s[i];
    }

    bool success = true;
    for (int j = 0; j < m; ++j)
    {
        long long idx = j * (z / m) + 1;
        if (mic.count(idx))
        {
            if (mic[idx] != t[j])
                success = false;
        }
    }

    cout << (success ? z : -1) << endl;
}