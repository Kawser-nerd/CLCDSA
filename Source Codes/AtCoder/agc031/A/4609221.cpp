#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

const long long mod = 1e9 + 7;
long long cnt[26];
long long N;
string s;

int main()
{
    cin >> N >> s;
    for (int i = 0; i < N;i++)
    {
        cnt[s[i] - 'a']++;
    }
    long long ans = 1;
    for (int i = 0; i < 26;i++)
    {
        ans = (ans * (cnt[i] + 1LL)) % mod;
        
        //ans *= (cnt[i] + 1LL);
        //ans %= mod;
    }
    ans = (ans - 1LL + mod) % mod;
    cout << ans << endl;
    return 0;
}