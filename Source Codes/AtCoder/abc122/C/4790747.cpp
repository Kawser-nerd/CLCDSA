#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, q, li, ri;
    int cnt = 0;
    string inputString;
    scanf("%d %d\n", &n, &q);
    cin >> inputString;
    int cntAC[n];
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (inputString[i] == 'A')
        {
            flag = 1;
        }
        if (inputString[i] == 'C' && flag == 1)
        {
            cnt += 1;
        }
        if (inputString[i] != 'A')
        {
            flag = 0;
        }
        cntAC[i] = cnt;
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &li, &ri);
        printf("%d\n", cntAC[ri - 1] - cntAC[li - 1]);
    }
    return 0;
}