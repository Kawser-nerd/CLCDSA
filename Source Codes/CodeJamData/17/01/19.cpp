#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++)
    {
        int n;
        string str;
        cin >> str >> n;
        int ans = 0;

        for (int i = 0; i < str.size() - n + 1; i++)
        {
            if (str[i] == '-')
            {
                    ++ans;
                for (int j = 0; j < n; j++)
                {
                    str[i+j] = (str[i+j] == '-') ? '+' : '-';
                }
            }
        }

        if (find(str.begin(), str.end(), '-') != str.end()) 
            printf("Case #%d: IMPOSSIBLE\n", tt);
            else
            printf("Case #%d: %d\n", tt, ans);
    }
}


