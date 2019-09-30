#include <stdio.h>

int main(){
  int n;
  int m = 10000;
  scanf("%d",&n);
  int prime[m],prime_mod5[n];
  prime[0] = 2;
  prime_mod5[0] = 2;
  int flag;
  int count = 1;
  for(int i = 1; i < m; ++i){
	if(count == n) break;
	for(int j = prime[i-1] + 1; j < 55555; ++j){
      flag = 0;
	  for(int k = 0; k < i; ++k){
		//printf("%d %d %d\n",i,j,prime[k]);
		if(j % prime[k] == 0) flag = 1;
		if(flag == 1) break;
	  }
	  if(flag == 0){
		prime[i] = j;
		if(prime[i] % 5 == 1){
		  prime_mod5[count] = prime[i];
		  count++;
		}
		break;
	  }
	}
  }
  for(int i = 0; i < n - 1; ++i){
	printf("%d ",prime_mod5[i]);
  }
  printf("%d\n",prime_mod5[n-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^