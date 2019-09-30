#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

double p[100000];
double q[100001];

double solve(){
    int A, B;
    scanf("%d %d", &A, &B);
    q[0] = 1.0;
    for(int i=0; i<A; i++)
    {
        scanf("%lf", p+i);
        q[i+1]=q[i]*p[i];
    }

    double ans = 2+B;
    for(int i=1; i<=A; i++)
    {
        double expect = 1+(B-A + 2*(A-i)) + (1-q[i])*(1+B);
        ans=min(ans, expect);
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        printf("Case #%d: %.6lf\n", t, solve());
    }
    return 0;
}
