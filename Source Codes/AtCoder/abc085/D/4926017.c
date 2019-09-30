#include <stdio.h>
#include <stdlib.h>
typedef struct data{
long long  a;
long long  b;
}Data;
int cmp(const void *p,const void *q){
if( *(long long*)q - *(long long*)p < 0 )
        return -1;
    if( *(long long*)q - *(long long *)p > 0 )
        return 1;
    return 0;
}
int cmpa(const void *p,const void *q){
if( ((Data*)q)->a - ((Data*)p)->a < 0 )
        return -1;
    if( ((Data*)q)->a - ((Data*)p)->a > 0 )
        return 1;
    return 0;
}
int main(){
    long long N,H,i,ans=0,max;
    scanf("%lld%lld",&N,&H);
    long long buf[2*N];
    Data d[N];
    
    for(i=0;i<N;i++)scanf("%lld%lld",&d[i].a,&d[i].b);
    qsort(d,N,sizeof(Data),cmpa);
    max=d[0].a;
    
    for(i=0;i<N;i++){
    buf[2*i]=d[i].a;
    buf[2*i+1]=d[i].b;
    }
    qsort(buf,2*N,sizeof(long long),cmp);
    
    i=0;
    while((i<(2*N))&&(buf[i]>=max)&&(H>0)){
    H-=buf[i];
    ans++;
    i++;
    }
    if(H>0){
    long long k=(H/max);
    ans+=k;
    if(H>k*max)ans++;
    }
    
    printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&N,&H);
     ^
./Main.c:27:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<N;i++)scanf("%lld%lld",&d[i].a,&d[i].b);
                     ^