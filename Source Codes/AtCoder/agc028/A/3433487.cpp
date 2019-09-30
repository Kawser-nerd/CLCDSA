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
    bool success = true;
    for (int j = 0; j < g; ++j)
    {
        if (s[j * z / m] != t[j * z / n])
        {
            success = false;
        }
    }

    cout << (success ? z : -1) << endl;
}