#include <stdio.h>
#include <stdlib.h>

int GCD(int ,int);

int main(void){
	
	long long int N,M,G,i,n,m;
	char *S,*T;
  
	scanf("%lld %lld",&N,&M);
	S = (char *)malloc((N+1)*sizeof(char));
	T = (char *)malloc((M+1)*sizeof(char));
	scanf("%s",S);
	scanf("%s",T);

	G = GCD(N,M);
  	n = N/G;
  	m = M/G;

	for(i=0;i<G;i++){
    	if(S[i*n] != T[i*m]){
 			printf("-1\n");       	
			free(S);
			free(T);
			return 0;
        }
    }
  
	printf("%lld\n",(long long int)(N/G*M));

	free(S);
	free(T);
	return 0;
}


int GCD(int a,int b){
	
	int tmp,r;
	
	if(a<b){
		tmp = a;
		a = b;
		b = tmp;
	}
	
	r = a % b;
	
	while(r != 0){
		a = b;
		b = r;
		r = a % b;
	}
  	return b;

} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&N,&M);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",T);
  ^