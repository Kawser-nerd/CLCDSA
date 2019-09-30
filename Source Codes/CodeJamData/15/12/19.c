#include<stdio.h>
int gcd(int a,int b)
{
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    return gcd(a,b-a);
}
int lcm(int a,int b)
{
    return b/gcd(a,b)*a;
}
int main(void){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int ti,i,j,n,b,m[100000],c[100000],ans,time,co,temp,all;
    scanf("%d",&ti);
    for(i=1;i<=ti;i++){
        scanf("%d%d",&b,&n);
        for(j=1;j<=b;j++){
            scanf("%d",&m[j]);
            c[j]=j;
        }
        if(b>1){
            temp=lcm(m[1],m[2]);
            for(j=3;j<=b;j++){
                temp=lcm(temp,m[j]);
            }
            all=0;
            for(j=1;j<=b;j++){
                all+=temp/m[j];
            }
        }
        co=b;
        time=0;
        ans=-1;
        n%=all;
        n+=all;
        if(b>=n && n!=0)
            ans=n;
        else if(b==1)
            ans=1;
        else if(n==0)
            ans=b;
        else{
            while(1){
                time++;
                for(j=1;j<=b;j++){
                    if(time%m[j]==0){
                        c[j]=++co;
                        if(co==n){
                            ans=j;
                            break;
                        }
                    }
                }
                if(ans>0)
                    break;
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
