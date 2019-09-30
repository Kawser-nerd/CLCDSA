#include <stdio.h>
#include <string.h>

int k, n;
char s[1001];
int neib[34][34];
int closure[34][34];
int balance[34];

int l33t (char x)
{
    switch (x)
    {
        case 'o': return 26;
        case 'i': return 27;
        case 'e': return 28;
        case 'a': return 29;
        case 's': return 30;
        case 't': return 31;
        case 'b': return 32;
        case 'g': return 33;
    }

    return x - 'a';
}

int work ()
{
    memset (neib, 0, sizeof(neib));
    for (int i = 0; i < n - 1; i ++)
    {
        neib[s[i] - 'a'][s[i + 1] - 'a'] = 1;
        neib[l33t(s[i])][s[i + 1] - 'a'] = 1;
        neib[s[i] - 'a'][l33t(s[i + 1])] = 1;
        neib[l33t(s[i])][l33t(s[i + 1])] = 1;
    }

    memset(balance, 0, sizeof(balance));

    int ans = 1;
    for (int i = 0; i < 34; i ++)
        for (int j = 0; j < 34; j ++)
            if (neib[i][j])
            {
                balance[i] ++;
                balance[j] --;
//                printf ("%d -> %d\n", i,j);
                ans ++;
            }
//            ans += neib[i][j];

    memcpy(closure, neib, sizeof(neib));
    for (int k = 0; k < 34; k ++)
        for (int i = 0; i < 34; i ++)
            for (int j = 0; j < 34; j ++)
                closure[i][j] |= closure[i][k] && closure[k][j];

    int td = 0;
    for (int i = 0; i < 34; i ++)
    {
        bool used = false;
        for (int j = 0; j < 34; j ++)
            if (neib[i][j] || neib[j][i])
            {
                used = true;
                break;
            }
        if (!used) continue;

        used = false;

        for (int j = 0; j < i; j ++)
            if (closure[i][j] && closure[j][i])
            {
                used = true;
                break;
            }

        if (!used)
        {
            bool ip = false, o = false;
            int diff = 0;
            for (int j = 0; j < 34; j ++)
                if (closure[i][j] && closure[j][i] || j == i)
                {
                    if (balance[j] > 0) diff += balance[j];
                    else diff -= balance[j];
//                    printf ("i = %d: j = %d\n", i, j);
                    for (int k = 0; k < 34; k ++)
                        if ((!closure[i][k] || !closure[k][i]) && k != i)
                        {
                            if (neib[j][k])
                                o = true;
                            if (neib[k][j])
                                ip = true;
                        }
                }
//            printf ("i = %d, ip = %d, op = %d\n", i, (int)ip, (int)o);

            if (!ip && !o && diff == 0)
                diff = 2;

            td += diff;
        }
    }

    return ans + td / 2 - 1;
}

int main ()
{
    int t, ct;

    scanf ("%d", &t);
    for (ct = 1; ct <= t; ct ++)
    {
        scanf ("%d%s", &k, s);
        n = strlen(s);
        printf ("Case #%d: %d\n", ct, work());
    }
}
