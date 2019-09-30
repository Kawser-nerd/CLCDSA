#include<stdio.h>
const int max_n=1000100;
int tc,tcn;
long long int n,r;
long long int maxd;
long long int ans;
int pf[1001000][10];
int pfn[1001000];
int copn(int x,int lim){
    int i,j,k,mult;
    int res=0;
    for(i=0;i<(1<<pfn[x]);i++){
        mult=1;
        k=1;
        for(j=0;j<pfn[x];j++){
            if((i>>j)%2==1){
                mult*=pf[x][j];
                k*=-1;
            }
        }
        res+=(lim/mult)*k;
    }
    return res;
}
int main(){
    long long int i,j,k;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&tcn);
    for(i=2;i<=max_n;i++){
        k=i;
        for(j=2;j*j<=k;j++){
            if(k%j==0){
                pf[i][pfn[i]]=j;
                pfn[i]++;
                while(k%j==0)k/=j;
            }
        }
        if(k!=1){
            pf[i][pfn[i]]=k;
            pfn[i]++;
        }
    }
    for(tc=1;tc<=tcn;tc++){
        scanf("%lld%lld",&n,&r);
        n--;
        maxd=999999999999LL/(r*r);
        k=n;
        ans=2;
        if(k>max_n)k=max_n;
        for(i=1;i<=n;i++){
            if(i*i>maxd)break;
            j=maxd-(i*i);
            while(k*k>j)k--;
            ans+=copn(i,k);
        }
        printf("Case #%d: %lld\n",tc,ans);
    }
    return 0;
}
