#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1e9 + 5;

int main()
{
    string s;
    int t[26];
    int mt[26];
    int ans = INF;

    cin >> s;
    int slen = s.length();

    for (int i = 0; i < 26; i++)
    {
        t[i] = -1;
        mt[i] = 0;
    }
    for (int i = 0; i < slen;i++)
    {
        int idx = s[i] - 'a';
        mt[idx] = max(mt[idx], i - t[s[i] - 'a']);
        t[s[i] - 'a'] = i;
    }
    ans = INF;
    for (int i = 0; i < 26; i++)
    {
        mt[i] = max(mt[i], slen - t[i]);
        if(t[i] != -1)
        {
            ans = min(ans, mt[i]);
        }
    }
    cout << ans - 1 << endl;

    return 0;
}