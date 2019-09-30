#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int n, a;
double t[10000], x[10000], H, A;

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    
    int TT;
    scanf("%d", &TT);
    for (int T=1;T<=TT;++T)
    {
        printf("Case #%d:\n", T);
        scanf("%lf %d %d", &H,&n,&a);
        for (int i=1;i<=n;++i)
            scanf("%lf %lf", t+i,x+i);
        x[0]=t[0]=0;
        for (int i=2;i<=n;++i)
            if (x[i]>=H)
            {
                double k=(H-x[i-1])/(x[i]-x[i-1]);
                x[i] = H;
                t[i] = (t[i]-t[i-1])*k + t[i-1];
                n = i;
                break;
            }
        for (int i=0;i<a;++i)
        {
            scanf("%lf", &A);
            for (int j=n;j>=0;)
            {
                double start = t[j] - sqrt(x[j]*2/A);
                bool flag = 1;
                for (int k=j-1;t[k]>=start && k>=0;--k)
                    if ((t[k]-start)*(t[k]-start)*A/2>x[k])
                    {
                        flag = 0;
                        j=k;
                        break;
                    }
                if (flag)
                {
                    printf("%.7f\n", start + sqrt(H*2/A));
                    break;
                }
            }
        } 
    }
}
