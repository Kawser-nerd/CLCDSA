#include <iostream>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    char c[10][10];
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=4;j++)
        {
            scanf("%c",&c[i][j]);
        }
    }
    if(c[1][1]==c[2][3]&&c[1][2]==c[2][2]&&c[1][3]==c[2][1])
    {
        printf("YES\n");
    }
    else printf("NO\n");
    return 0;
}