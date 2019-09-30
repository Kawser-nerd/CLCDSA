#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

int x[100],y[100],r[100];

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    freopen("D-small-attempt2.in","r",stdin);
    freopen("D-small-attempt2.out","w",stdout);
    double best,maxr;
    int l,t,i,j,k,n;
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&r[i]);

        }
        if (n==1)
        {
            printf("Case #%d: %.6lf\n",l+1,(double)r[0]);
            continue;
        }

        if (n==2)
        {
            maxr=r[0];
            if (r[1]>maxr) maxr=r[1];
            printf("Case #%d: %.6lf\n",l+1,maxr);
            continue;
        }
        best=1e10;
        for (i=0;i<n;i++)
        {
            maxr=r[i];
            for (j=0;j<n;j++)
                if (j!=i) break;
            for (k=j+1;k<n;k++)
                if (k!=i) break;
            if ((dis(x[j],y[j],x[k],y[k])+r[j]+r[k])/2>maxr)
                maxr=(dis(x[j],y[j],x[k],y[k])+r[j]+r[k])/2;
            if (maxr<best) best=maxr;
        }
        printf("Case #%d: %.6lf\n",l+1,best);
    }
	return 0;
}

