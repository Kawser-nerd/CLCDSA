#include <stdio.h>
#include "stdlib.h"

#define MAX 1000002013

long long a[1100][3],b[2200][3],stak[2000][2];

int comp(const void *a,const void *b){
    
    long long tmp;
    
    tmp=((long long *)a)[0]-((long long *)b)[0];
    
    if (tmp>0){
        
        return 1;
    }
    else if (tmp<0){
        
        return -1;
    }
    else {
        
        tmp=((long long *)a)[2]-((long long *)b)[2];
        
        if (tmp>0){
            
            return 1;
        }
        else if (tmp<0){
            
            return -1;
        }
        else {
            
            return 0;
        }
    }
}

long long trans(long long k){
    
    return ((k*(k+1))/2)%MAX;
}

int main(){
    
    long long t,tt,n,m,mm,ans,i,j,x,x1;
    
    
    
    freopen("A-large.in.txt", "r",stdin);
    freopen("A-large.out.txt", "w",stdout);

    
    scanf("%lld",&t);
    
    for (tt=1;tt<=t;tt++){
        
        scanf("%lld%lld",&n,&m);
        
        ans=0;
        
        for (i=0;i<m;i++){
            
            scanf("%lld%lld%lld",a[i],a[i]+1,a[i]+2);
            
            ans+=MAX;
            ans-=(a[i][2]*trans(a[i][1]-a[i][0]))%MAX;
            
            ans%=MAX;
            
            b[i*2][0]=a[i][0];
            b[i*2][1]=a[i][2];
            b[i*2][2]=0;
            
            b[i*2+1][0]=a[i][1];
            b[i*2+1][1]=a[i][2];
            b[i*2+1][2]=1;
        }
        mm=m*2;
        
        qsort(b, mm, sizeof(long long )*3, comp);
        
        for (j=0,i=0;i<mm;i++){
            
            if (b[i][2]==0){
                
                j++;
                stak[j][0]=b[i][0];
                stak[j][1]=b[i][1];
            }
            else {
                
                x=b[i][0];
                x1=b[i][1];
                
                while (x1>0){
                    
                    if (x1>=stak[j][1]){
                        
                        ans+=(trans(x-stak[j][0])*stak[j][1])%MAX;
                        ans%=MAX;
                        
                        x1-=stak[j][1];
                        j--;
                    }
                    else {
                        
                        ans+=(trans(x-stak[j][0])*x1)%MAX;
                        ans%=MAX;
                        
                        stak[j][1]-=x1;
                        x1=0;
                    }
                }
            }
        }
        
        printf("Case #%lld: %lld\n",tt,ans);
        
    }
    return 0;
}

