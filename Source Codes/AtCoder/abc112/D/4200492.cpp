#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
 
using namespace std;
int n, m;
int ans;
 
int main()
{
    scanf("%d%d",&n,&m);
    int c = m/n;
    int b = sqrt(m);
    c = min(c, b);
    for (int i = 1; i * i <= m; ++i)
    {
        if (m % i == 0) 
        {
            int i1 = i;
            int i2 = m / i;
            if (i1 <= m / n) ans = max(ans, i1); 
            if (i2 <= m / n) ans = max(ans, i2);
        }
    }
    cout << ans;
}