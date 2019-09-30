#include <stdio.h>
#include <math.h>

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int D,ans = 60000;
  long long G;
  scanf("%d%lld",&D,&G);

  int p[D];
  long long c[D];
  for(int i = 0;i < D;i++){
    scanf("%d%lld",&p[i],&c[i]);
  }

  int sample,counter,restmax,num;
  long long sum;
  int length = 0;
  sample = pow(2,D)-1;
  while(sample > 0){
    sample /= 2;
    length++;
  }
  for(int i = 0;i < pow(2,D);i++){
    sample = i;
    counter = 0;
    sum = 0;
    num = 0;
    while(counter < length){
      if(sample%2 != 0){
        sum += 100*(counter+1)*p[counter]+c[counter];
        num += p[counter];
      }else{
        restmax = counter;
      }
      sample /= 2;
      counter++;
    }
    if(sum >= G){
      ans = min(ans,num);
    }else if(sum + 100*(restmax+1)*(p[restmax]-1) >= G){
      int need = 0;
      while(sum+100*(restmax+1)*need < G){
        need++;
      }
      num += need;
      if(need < p[restmax]){
        ans = min(ans,num);
      }
    }
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&D,&G);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%lld",&p[i],&c[i]);
     ^