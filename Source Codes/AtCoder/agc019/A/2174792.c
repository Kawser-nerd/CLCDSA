#include <stdio.h>
int main(){
	long long int Q[5];
	long long int Qex[5];
	int i,j;
	long long int min;
	long long int N,result=0;
	scanf("%lld%lld%lld%lld",&Q[0],&Q[1],&Q[2],&Q[3]);
	scanf("%lld",&N);	
	
	N=N*4;//????????
	
	Qex[0]=8*Q[0];
	Qex[1]=4*Q[1];
	Qex[2]=2*Q[2];
	Qex[3]=Q[3];
	min=Qex[3];
	for(i=2;i>=0;i--)
	{
		if(min>=Qex[i]){
			min=Qex[i];
			}
	}
	
	if(min==Qex[3])
	{
		result=result+Q[3]*(N-N%8)/8;
	    N=N%8;
	    min=Qex[2];
	for(i=1;i>=0;i--)
	{
		if(min>=Qex[i]){
			min=Qex[i];
			}
	}
	}
	
	if(min==Qex[2])
	{
		result=result+Q[2]*(N-N%4)/4;
	    N=N%4;
	    min=Qex[1];
	for(i=0;i>=0;i--)
	{
		if(min>=Qex[i]){
			min=Qex[i];
			}
	}
	}
	
	if(min==Qex[1])
	{
		result=result+Q[1]*(N-N%2)/2;
	    N=N%2;
	    min=Qex[0];
	}
	
	if(min==Qex[0])
	{
		result=result+Q[0]*N;
	}
	
	printf("%lld",result);
	} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&Q[0],&Q[1],&Q[2],&Q[3]);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&N); 
  ^