#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//????????????m????n-m?
const int maxn = 1e5+5;
int main()
{
    char s[maxn];
    int len;
    int res;
    scanf("%s", s);
    len = strlen(s);
    res = len;
    for(int i = 1; i < len; i++)
    {
        if(s[i] != s[i-1])
            res = min(res, max(i, len-i));
    }
    printf("%d\n", res);
    return 0;
}