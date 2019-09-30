#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n,k;
double S;
double A[55];

int main()
{
    #ifdef LOCAL
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("c.out","w",stdout);
    #endif //LOCAL
    int T_T;
    scanf("%d",&T_T);
    for (int cas=1;cas<=T_T;cas++)
    {
        scanf("%d%d",&n,&k);
        scanf("%lf",&S);
        for(int i=0;i<n;i++) scanf("%lf",&A[i]);
        A[n++]=1.0;
        sort(A,A+n);

        double now_l=A[0],now_S=S;
        for(int i=1;i<n;i++)
        {
            if(i*(A[i]-now_l)>now_S)
            {
                now_l+=now_S/i;
                now_S=0.0;
                break;
            }
            else
            {
                now_S-=i*(A[i]-now_l);
                now_l=A[i];
            }
        }

        double Pro=1.0;
        for(int i=0;i<n;i++) Pro *= A[i]<now_l ? now_l : A[i] ;
        printf("Case #%d: %.12lf\n",cas,Pro);
    }
    return 0;
}
