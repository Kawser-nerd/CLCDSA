#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int sort(const void * a, const void * b)
{
    if( *(long long int*)a - *(long long int*)b < 0 )
        return 1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return -1;
    return 0;
}

int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    long long x[n],y[n],z[n],score[n],ans=0,tmp=0;
    
    for (int i=0; i<n; i++){
        scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
    }
    
    for (int i=0; i<n; i++){
        score[i]=x[i]+y[i]+z[i];
    }
    qsort (score,n,sizeof(long long),sort);
    for (int i=0; i<m; i++){
        tmp+=score[i];
    }
    if(ans<tmp){
        ans=tmp;
    }
    tmp=0;
    
    for (int i=0; i<n; i++){
        score[i]=x[i]+y[i]-z[i];
    }
    qsort (score,n,sizeof(long long),sort);
    for (int i=0; i<m; i++){
        tmp+=score[i];
    }
    if(ans<tmp){
        ans=tmp;
    }
    tmp=0;
    
    for (int i=0; i<n; i++){
        score[i]=x[i]-y[i]+z[i];
    }
    qsort (score,n,sizeof(long long),sort);
    for (int i=0; i<m; i++){
        tmp+=score[i];
    }
    if(ans<tmp){
        ans=tmp;
    }
    tmp=0;
        
    for (int i=0; i<n; i++){
        score[i]=x[i]-y[i]-z[i];
    }
    qsort (score,n,sizeof(long long),sort);
    for (int i=0; i<m; i++){
        tmp+=score[i];
    }
    if(ans<tmp){
        ans=tmp;
    }
    tmp=0;
    
    for (int i=0; i<n; i++){
        score[i]=0-x[i]+y[i]+z[i];
    }
    qsort (score,n,sizeof(long long),sort);
    for (int i=0; i<m; i++){
        tmp+=score[i];
    }
    if(ans<tmp){
        ans=tmp;
    }
    tmp=0;

    for (int i=0; i<n; i++){
        score[i]=0-x[i]+y[i]-z[i];
    }
    qsort (score,n,sizeof(long long),sort);
    for (int i=0; i<m; i++){
        tmp+=score[i];
    }
    if(ans<tmp){
        ans=tmp;
    }
    tmp=0;
    
    for (int i=0; i<n; i++){
        score[i]=0-x[i]-y[i]+z[i];
    }
    qsort (score,n,sizeof(long long),sort);
    for (int i=0; i<m; i++){
        tmp+=score[i];
    }
    if(ans<tmp){
        ans=tmp;
    }
    tmp=0;
        
    for (int i=0; i<n; i++){
        score[i]=0-x[i]-y[i]-z[i];
    }
    qsort (score,n,sizeof(long long),sort);
    for (int i=0; i<m; i++){
        tmp+=score[i];
    }
    if(ans<tmp){
        ans=tmp;
    } 
    tmp=0;
    
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
         ^