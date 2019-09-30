#include<stdio.h>

int main(){
	long long N;
	scanf("%lld",&N);
	long long maxi;
	for(long long i=1;i*i<=N;i++){
		if(N%i==0)maxi=i;
	}
	long long A=maxi,a=0;
	long long B=N/maxi,b=0;

	while(B!=0){
		B/=10;
		b++;
	}
	printf("%d\n",b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d\n",b);
         ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&N);
  ^