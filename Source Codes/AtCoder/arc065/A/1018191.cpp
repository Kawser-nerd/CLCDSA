#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100001];
int l;

int dp[100001];
bool rec(int i)
{
    if (i == l)
        return true;
    if (i + 5 > l)
        return false;
    if (dp[i] != -1)
        return dp[i];

    bool ans = false;
    if (s[i] == 'd' && s[i + 1] == 'r' && s[i + 2] == 'e' && s[i + 3] == 'a' && s[i + 4] == 'm') {
        if (i + 7 <= l && s[i + 5] == 'e' && s[i + 6] == 'r')
            ans = ans || rec(i + 7);
        ans = ans || rec(i + 5);
    } else if (s[i] == 'e' && s[i + 1] == 'r' && s[i + 2] == 'a' && s[i + 3] == 's' && s[i + 4] == 'e') {
        if (i + 6 <= l && s[i + 5] == 'r')
            ans = ans || rec(i + 6);
        ans = ans || rec(i + 5);
    }
    return dp[i] = ans;
}

int main()
{
    scanf("%s", s);
    l = strlen(s);

    fill(dp, dp + 100001, -1);

    if (rec(0))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}