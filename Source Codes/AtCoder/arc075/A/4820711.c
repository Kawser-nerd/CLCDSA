#include<stdio.h>
#include<stdlib.h>
int main(){
	int N,i,s[100],sum=0,j,k =111,temp;
	scanf("%d",&N);
	
	for(i = 0;i<N;i++){
		scanf("%d",&s[i]);
		sum+=s[i];
	}
	for (i = 0; i < (N - 1); i++) {
    for (j = (N - 1); j > i; j--) {
      if (s[j-1] > s[j]) {
        temp = s[j-1];
        s[j-1] = s[j];
        s[j] = temp;
      }
    }
  }
	for(i = 0;i<N;i++){
		if(s[i] != 0 && s[i] <10 && k==111){
			
			k=i;
		}else
		if(s[i] % 10 != 0 && k==111){
			k=i;
		}
	}
	if(sum % 10 != 0){
		printf("%d\n",sum);
	}else if(k!=111){
		printf("%d\n",sum-s[k]);
	}else{
		printf("0\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&s[i]);
   ^