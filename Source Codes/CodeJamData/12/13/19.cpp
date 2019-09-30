#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

double p[55],s[55];
int f[10000][1<<6];
int n,t,id;

int main()
{
    for (scanf("%d",&t);t--;)
    {
        int state=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            char ss[5];
            scanf("%s%lf%lf",ss,&s[i],&p[i]);
            if (ss[0]=='R') state+=(1<<i);
        }

        vector<double> x;
        for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            if (fabs(p[j]-p[i])<5)
            {
                x.push_back(0);
                if (p[i]>=p[j] && s[i]>s[j])
                    x.push_back((p[j]+5-p[i])/(s[i]-s[j]));
            }

            if (p[i]<=p[j] && s[i]>s[j])
            {
                x.push_back(max(0.0,(p[j]-p[i]-5)/(s[i]-s[j])));
                x.push_back(max(0.0,(p[j]-p[i]+5)/(s[i]-s[j])));
            }
        }
        x.push_back(0);x.push_back(0);
        x.push_back(10000000);
        sort(x.begin(),x.end());
        for (int i=0;i<x.size();i++)
        for (int j=0;j<(1<<n);j++)
            f[i][j]=0;

        double res=0;
        f[0][state]=1;
        for (int i=0;i<x.size()-1;i++)
        for (int j=0;j<(1<<n);j++)
        if (f[i][j])
        {
            res=x[i];
            double tt=(x[i]+x[i+1])/2;
            bool ok=1;
            for (int a=0;a<n;a++)
            for (int b=a+1;b<n;b++)
            if (((j&(1<<a))>0)==((j&(1<<b))>0))
                ok&=(fabs(p[a]+s[a]*tt-p[b]-s[b]*tt)>=5-(1e-7));
            if (!ok) continue;
            
            res=x[i+1];
            tt=x[i+1];
            for (int k=0;k<(1<<n);k++)
            {
                ok=1;
                for (int a=0;a<n;a++)
                for (int b=a+1;b<n;b++)
                if (((j&(1<<a))>0)!=((k&(1<<a))>0) &&
                    ((j&(1<<b))>0)!=((k&(1<<b))>0))
                    ok&=(fabs(p[a]+s[a]*tt-p[b]-s[b]*tt)>=5-(1e-7));
                if (ok) f[i+1][k]=1;
            }
        }

        printf("Case #%d: ",++id);
        if (res>5000000) printf("Possible\n");
        else printf("%.10lf\n",res);
    }
}






