#include<stdio.h>

int main(){
  long d,g,p[10],c[10],dp[1010][11]={},a[10],b,co[10][2],sum=0,maxx=0,sa,sumx;
  long f[10],n=1,num,ans;
  scanf("%ld %ld",&d,&g);
  for(long i=0;i<d;i++){
    n*=2;
    scanf("%ld %ld",&p[i],&c[i]);
  }
  for(long i=0;i<d;i++){
    co[i][0]=(1+i)*p[i]*100+c[i];
    co[i][1]=p[i];
  }
  for(long i=1;i<=1000;i++){
    for(long j=0;j<n;j++){
      num=j;
      sum=0;
      sumx=0;
      for(long k=0;k<d;k++){
        f[k]=num%2;
        num/=2;
        sum+=f[k]*p[k];
        sumx+=co[k][0]*f[k];
      }
      if(i>=sum){
        sa=i-sum;
        for(long k=d-1;k>=0;k--){
          if(f[k]==0){
            if(sa<p[k]){
              sumx+=sa*(k+1)*100;
              sa=0;
              break;
            }
            else{
              sumx+=p[k]*(k+1)*100;
              sa-=p[k];
            }
          }
        }
        if(maxx<sumx){
          maxx=sumx;
        }
      }
    }
    if(maxx>=g){
      ans=i;
      break;
    }
  }
  printf("%ld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld",&d,&g);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld",&p[i],&c[i]);
     ^