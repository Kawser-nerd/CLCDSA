#define ll long long
typedef struct matrix{ll a[2][2];}mat;
mat a,b;
int n,x,ans,mod;
void mul(mat a,mat b,mat*c)
{
    int i,j,k;
    memset((*c).a,0,sizeof((*c).a));
    for(i=0; i<2; i++)
    for(j=0; j<2; j++)
    {
        for(k=0; k<2; k++)
        (*c).a[i][j]+=a.a[i][k]*b.a[k][j];
        (*c).a[i][j]%=mod;
    }
}
int Pow(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1)
        ret=ret*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return ret;
}
main()
{
    int _,t;
    scanf("%d",&_);
    for(t=1; t<=_; t++)
    {
        scanf("%d",&x);
        n=x;
        mod=1000;
        a.a[0][0]=0,a.a[0][1]=a.a[1][0]=a.a[1][1]=1;
        b.a[0][0]=b.a[1][1]=1,b.a[0][1]=b.a[1][0]=0;
        for(x--;x;x/=2)
        {
            if(x&1)
            mul(b,a,&b);
            mul(a,a,&a);
        }
        ans=(b.a[0][0]+b.a[1][0])%mod;
        ans=(ans*ans*5)%mod;
        if(n&1)
        ans-=2;
        else
        ans+=2;
        ans*=Pow(2,n);
        printf("Case #%d: %03d\n",t,(ans+mod-1)%mod);
    }
    return 0;
}
