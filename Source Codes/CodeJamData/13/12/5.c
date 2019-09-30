#include <stdio.h>

long long v[20000],d[20000][2];

int main(){
    
    long t,tt,i,n,le,ri;
    long long e,r,cur,ans,tmp,x;
    
    freopen("B-large.in.txt", "r",stdin);
    freopen("B-large.out.txt", "w",stdout);

    
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        
        scanf("%lld%lld%ld",&e,&r,&n);
        for (i=1;i<=n;i++){
            
            scanf("%lld",v+i);
        }
        
        cur=0;
        le=0;
        ri=0;
        d[le][0]=0;
        d[le][1]=0;
        
        ans=0;
        
        for (i=n;i>=0;i--){
            
            if (i>0)
                tmp=r;
            else
                tmp=e;
            
            while ((tmp>0)&&(le<=ri)){
                
                x=d[le][1]-cur;
                
                if (x>tmp){
                    
                    ans+=tmp*d[le][0];
                    cur+=tmp;
                    tmp=0;
                }
                else {
                    
                    ans+=x*d[le][0];
                    cur+=x;
                    tmp-=x;
                    le++;
                }
            }
            
            while ((ri>=le)&&(v[i]>=d[ri][0])){
                
                ri--;
            }
            
            ri++;
            d[ri][0]=v[i];
            d[ri][1]=cur+e;
        }
        
        printf("Case #%ld: %lld\n",tt,ans);
    }
    return 0;
}

