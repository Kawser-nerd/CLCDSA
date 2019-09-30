#include<stdio.h>
#define ll long long
#define pie 3.141592653589793238462643383279

static ll int m[3][1002];

void mer(ll int p,ll int q,ll int r)
{   static ll int le[3][1002],ri[3][1002],i,j,k;
    ll int n1=q-p+1,n2=r-q;
    for(i=0;i<n1;i++)
    {
        le[0][i]=m[0][p+i];
        le[1][i]=m[1][p+i];
        le[2][i]=m[2][p+i];
    }
    for(j=0;j<n2;j++)
    {
        ri[0][j]=m[0][q+j+1];
        ri[1][j]=m[1][q+j+1];
        ri[2][j]=m[2][q+j+1];
    }
    le[2][n1]=ri[2][n2]=0;
    le[0][n1]=ri[0][n2]=0;
    le[1][n1]=ri[1][n2]=0;
    i=j=0;
    for(k=p;k<=r;k++)
    {   if(le[2][i]>ri[2][j])
        {   m[2][k]=le[2][i];
            m[0][k]=le[0][i];
            m[1][k]=le[1][i];
            i++;
        }
        else if(le[2][i]==ri[2][j] && le[0][i]>=ri[0][j])
        {   m[2][k]=le[2][i];
            m[0][k]=le[0][i];
            m[1][k]=le[1][i];
            i++;
        }
        else
        {   m[2][k]=ri[2][j];
            m[0][k]=ri[0][j];
            m[1][k]=ri[1][j];
            j++;
        }
    }
}
void merge_sort(ll int p,ll int r)
{   ll int q;
    if(p<r)
    {   q=(p+r)/2;
        merge_sort(p,q);
        merge_sort(q+1,r);
        mer(p,q,r);
    }
}

int main()
{
    static ll int t,n,k,i,j,r,x,y;
    double ans,p=3.141592653589793238462643383279,temp;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%lld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%lld%lld",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&m[0][i],&m[1][i]);
            m[2][i]=2*m[0][i]*m[1][i];
        }
        merge_sort(0,n-1);
        r=y=0;
        ans=0.0;
        for(i=0;i<k;i++)
        {
            ans=ans+m[2][i];
            if(m[0][i]>r)
                r=m[0][i];
        }
        ans=(ans+r*r);
        y=k-1;
        for(i=k;i<n;i++)
        {
            if(m[0][i]>r)
            {
                temp=ans-r*r+m[0][i]*m[0][i]+m[2][i]-m[2][y];
                if(temp>ans)
                {
                    ans=temp;
                    y=i;
                    r=m[0][i];
                }
            }
        }
        ans=ans*p;
        printf("Case #%lld: %lf\n",j,ans);
    }
    return 0;
}
