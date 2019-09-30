#include<stdio.h>
#include<string.h>

int main(){

	char S[100000];
	long long i;
	long long num = 0;

	scanf("%s",S);						//???
	for(i=0; S[i]!= 0; ++i);			//???



	for(int j=1; j<=i;j++){
		if(S[j-1] == 'U'){
			num += (i - j) + (j-1)*2;
		}else if(S[j-1] == 'D'){
			num += (i - j)*2 + (j-1);
		}
	}


	printf("%lld\n",num);
	//printf("%lld\n",i);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);      //???
  ^