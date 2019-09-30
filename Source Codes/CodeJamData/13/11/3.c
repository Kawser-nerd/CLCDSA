#include <stdio.h>

int tryans(long long r,long long t,long long k){
    
    long double tmp1,tmp2;
    long long tmp3;
    
    tmp2=r;
    tmp2=2*r;
    tmp2+=k;
    tmp2+=k;
    tmp2-=1;
    
    tmp1=k*tmp2;
    
    if (tmp1>2*t){
        
        return 0;
    }
    else {
        
        tmp3=k*(2*r+2*k-1);
        
        if (tmp3<=t){
            
            return 1;
        }
        else {
            
            return 0;
        }
    }
}

int main(){
    
    long te,tt;
    long long r,t,le,ri,mi;

    freopen("A-large.in.txt", "r",stdin);
    freopen("A-large.out.txt", "w",stdout);

    
    scanf("%ld",&te);
    for (tt=1;tt<=te;tt++){
        
        scanf("%lld%lld",&r,&t);
        
        le=0;
        ri=1000000000;
        
        while (le<ri){
            
            mi=(le+ri+1)/2;
            
            if (tryans(r,t,mi)){
                
                le=mi;
            }
            else {
                
                ri=mi-1;
            }
        }
        
        printf("Case #%ld: %lld\n",tt,ri);
    }
    return 0;
}

