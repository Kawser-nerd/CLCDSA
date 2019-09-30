#include <stdio.h>
#include <string.h>

int main()
{
    int n, testcase;
    char str[512];
    int f[18];
    scanf("%d\n", &n);
    for(testcase = 1; testcase <= n; testcase++)
    {
        int ans = 0;
        char *s = str;
        memset(f, 0, sizeof(f));
        gets(s);
        for(; *s; s++)switch(*s)
        {
            case 'w': f[0] = (f[0] + 1) % 10000; break;
            case 'e': f[1] = (f[1] + f[0]) % 10000; f[6] = (f[6] + f[5]) % 10000; f[14] = (f[14] + f[13]) % 10000; break;
            case 'l': f[2] = (f[2] + f[1]) % 10000; break;
            case 'c': f[3] = (f[3] + f[2]) % 10000; f[11] = (f[11] + f[10]) % 10000; break;
            case 'o': f[4] = (f[4] + f[3]) % 10000; f[9] = (f[9] + f[8]) % 10000; f[12] = (f[12] + f[11]) % 10000; break;
            case 'm': f[5] = (f[5] + f[4]) % 10000; ans = (ans + f[17]) % 10000; break;
            case ' ': f[7] = (f[7] + f[6]) % 10000; f[10] = (f[10] + f[9]) % 10000; f[15] = (f[15] + f[14]) % 10000; break;
            case 't': f[8] = (f[8] + f[7]) % 10000; break;
            case 'd': f[13] = (f[13] + f[12]) % 10000; break;
            case 'j': f[16] = (f[16] + f[15]) % 10000; break;
            case 'a': f[17] = (f[17] + f[16]) % 10000;
        }
        printf("Case #%d: %d%d%d%d\n", testcase, \
         ans / 1000, ans / 100 % 10, ans /10 % 10, ans %10);
    }
    return 0;
}

