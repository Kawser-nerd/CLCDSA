#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i < dp.size(); i++) {
        if (i >= 5 && dp[i - 5]) {
            if (s[i - 5] == 'd' && s[i - 4] == 'r' && s[i - 3] == 'e' && s[i - 2] == 'a' && s[i - 1] == 'm')
                dp[i] = true;
            else if (s[i - 5] == 'e' && s[i - 4] == 'r' && s[i - 3] == 'a' && s[i - 2] == 's' && s[i - 1] == 'e')
                dp[i] = true;
        }
        if (i >= 6 && dp[i - 6]) {
            if (s[i - 6] == 'e' && s[i - 5] == 'r' && s[i - 4] == 'a' && s[i - 3] == 's' && s[i - 2] == 'e' && s[i - 1] == 'r')
                dp[i] = true;
        }
        if (i >= 7 && dp[i - 7]) {
            if (s[i - 7] == 'd' && s[i - 6] == 'r' && s[i - 5] == 'e' && s[i - 4] == 'a' && s[i - 3] == 'm' && s[i - 2] == 'e' && s[i - 1] == 'r')
                dp[i] = true;
        }
    }
    if (dp[dp.size() - 1])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}