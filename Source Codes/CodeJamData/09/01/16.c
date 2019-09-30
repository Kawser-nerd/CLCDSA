#include <stdio.h>
#include <string.h>

#define MAXL 15
#define MAXD 5000

char word[MAXD][MAXL + 1];
int pattern[MAXL + 1]['z' + 1];

int main()
{
    int l, d, n, i, j, k;
    scanf("%d%d%d", &l, &d, &n);
    for(i = 0; i < d; i++)scanf("%s\n", word[i]);
    for(i = 1; i <= n; i++)
    {
        int ans = 0;
        char ch = getchar();
        memset(pattern, 0, sizeof(pattern));
        for(j = 0; ch != '\n'; j++)
        {
            if(ch == '(')
                while((ch = getchar())!= ')')
                    pattern[j][(int)ch] = 1;
            else
                pattern[j][(int)ch] = 1;
            ch = getchar();
        }
        for(j = 0; j < d; j++)
        {
            for(k = l - 1; k >= 0; k--)if(!pattern[k][(int)word[j][k]])break;
            if(k < 0)ans++;
        }
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
