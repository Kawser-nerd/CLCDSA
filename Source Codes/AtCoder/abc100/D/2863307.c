#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long N,M;
long x[1000],y[1000],z[1000];

long max(long a,long b){
  if(a > b) return a;
  else return b;
}

long func(){
  int i,j,k,l;
  long num[1000];
  long ans=-100000000000LL;
  for(i=0;i<8;i++){
    for(j=0;j<N;j++){
      num[j] = 0LL;
      if(i&1) num[j] += -1 * x[j];
      else num[j] += x[j];
      if(i&2) num[j] += -1 * y[j];
      else num[j] += y[j];
      if(i&4) num[j] += -1 * z[j];
      else num[j] += z[j];
    }
    for (k=0; k<N; k++) {
      for (l=k+1; l<N; l++) {
	if (num[k] < num[l]) {
	  long tmp =  num[k];
	  num[k] = num[l];
	  num[l] = tmp;
	}
      }
    }
    long res = 0LL;
    for(k=0;k<M;k++){
      res += num[k];
    }
    ans = max(ans,res);
  }
  return ans;
}


int main(int argc,char *argv[]){
  int i,j;
  scanf("%ld %ld",&N,&M);
  for(i=0;i<N;i++){
    scanf("%ld %ld %ld",&x[i],&y[i],&z[i]);
  }
  printf("%ld\n",func());
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld",&N,&M);
   ^
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld",&x[i],&y[i],&z[i]);
     ^