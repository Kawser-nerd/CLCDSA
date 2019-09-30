#include<stdio.h>
#include<sys/time.h>

unsigned long long seed;

unsigned long long xorshift(){
  seed=seed^(seed<<13);
  seed=seed^(seed>>7);
  seed=seed^(seed<<17);
  return seed;
}

int main(void){
    long long i,n,m,k,a,b,fl[16][16]={0},st[16],w;
    long long ok=0,tt=0;
    long long stt,nt;
    double res;
    scanf("%lld%lld%lld",&n,&m,&k);
    struct timeval tv;
    gettimeofday(&tv, NULL);
    seed=(tv.tv_sec*1000000+tv.tv_usec);
    stt=seed;
    for(i=0;i<m;i++){
      scanf("%lld%lld",&a,&b);
      fl[a][b]=1;
      fl[b][a]=1;
    }
    while(1){
      for(i=0;i<n;i++){
        st[i]=i;
      }

      for(i=0;i<k;i++){
        a=xorshift()%n;
        b=xorshift()%(n-1);
        if(a<=b){b++;}
        w=st[a];
        st[a]=st[b];
        st[b]=w;
      }

      if(fl[st[n-1]][st[0]]==0){
        w=1;
        for(i=1;i<n;i++){
          if(fl[st[i-1]][st[i]]==1){w=0;break;}
        }
        ok+=w;
      }

      tt++;
      if(tt%10000==0){
        gettimeofday(&tv, NULL);
        nt=(tv.tv_sec*1000000+tv.tv_usec);
        if(nt-stt>9000000){break;}
      }
    }
    res=ok;
    res/=tt;
    printf("%.12lf\n",res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&n,&m,&k);
     ^
./Main.c:24:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld%lld",&a,&b);
       ^