#include <stdio.h>

int main(){
    
    long long t,tt,n,nn,k,i,j,ans1,ans2;
    
    freopen("B-large.in.txt", "r",stdin);
    freopen("B-large.out.txt", "w",stdout);    

    
    scanf("%lld",&t);
    
    for (tt=1;tt<=t;tt++){
        
        scanf("%lld%lld",&n,&k);
        
        for (nn=1,i=0;i<n;i++){
            
            nn*=2;
        }
        
        i=nn-k;
        i*=2;
        
        if(i==0){
            
            ans1=nn-1;
        }
        else {
        
            for (ans1=0,j=1;i<nn;ans1+=j){
                
                i*=2;
                j*=2;
            }
        }
        ans2=nn;
        
        for (i=k,j=1;i<nn;ans2=nn-j){
            
            i*=2;
            j*=2;
        }
        
        if (ans2==nn){
            
            ans2=nn-1;
        }
        
        printf("Case #%lld: %lld %lld\n",tt,ans1,ans2);
    }
    return 0;
}

