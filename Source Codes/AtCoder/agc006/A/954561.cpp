#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 105;
char s[maxn], t[maxn];

int main()
{
    int n;
    int i, j;
    int num;
    while(scanf("%d", &n)==1&&n)
    {
        scanf("%s", s);
        scanf("%s", t);
        if(strcmp(s, t)==0)
            printf("%d\n", n);
        else
        {
            int len1 = strlen(s);
            int len2 = strlen(t);
            i = 0;
            num = 0;
    //        for(int i = 0; i < len1;)
    //        {
                for(j = 0; j < len2&& i< len1;)
                {
                    if(t[j]==s[i])
                    {
                        num++;
                        i++;
                        j++;
    //                    break;
                    }
                    else
                    {
                        i++;
                    }
                }
    //        }
            printf("%d\n", 2*n-num);
        }
    }
    return 0;
}