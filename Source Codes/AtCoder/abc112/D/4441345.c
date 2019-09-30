#include <stdio.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main(){
  long int n,m,i,ans=1;
  scanf("%ld%ld",&n,&m);
  long int cd[100001],cent=sqrtl(m),j=0;
  for(i=1;i<cent;i++){
    if(m%i==0){
      cd[j]=i;
      cd[j+1]=m/i;
      j+=2;
    }
  }
  if(m%cent==0){
    cd[j]=cent;
    j++;
  }
  else cd[j]=0;
  for(i=0;i<=j;i++) if(cd[i]<=m/n)ans=max(ans,cd[i]);
  printf("%ld",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld",&n,&m);
   ^