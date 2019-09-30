#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{int N,M,B,X,C,x,i,a,b,c,l,r,g,flag,m,tmp;
	long long int sum;
	scanf("%d",&N);
	sum=1;
	flag=0;
	int A[100000];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);}
		qsort(A, N, sizeof(int), compare_int);
if(N%2==0){
	for(i=0;2*i+1<N;i++){
		if(A[2*i]!=2*i+1||A[2*i+1]!=2*i+1){
			flag=1;
			break;}}
			if(flag==0){
			
			x=N/2;
			for(a=1;a<=x;a++){
			sum*=2;
			if(sum>=1000000007){
				sum%=1000000007;}}}
	}
	else{
	for(i=0;2*i+1<N-1;i++){
		if(A[2*i]!=2*i||A[2*i+1]!=2*i+2||A[N-1]!=N-1){
			flag=1;
			break;}}
			if(flag==0){
			x=N/2;
			for(a=1;a<=x;a++){
			sum*=2;
			if(sum>=1000000007){
				sum%=1000000007;}}}}
	
	if(flag==0){
	printf("%lld",sum);}
	else
	printf("0");
			


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A[i]);}
   ^