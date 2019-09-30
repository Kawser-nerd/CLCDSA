#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{return *(int *)a-*(int *)b;}

int main(){
  int N,M;
  int A,S[100001]={0};
  long long int n=1,sum=0;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&A);
    S[i+1]=(S[i]+A)%M;
  }
 
  qsort(S,N+1,sizeof(int),cmp);
  for(int i=1;i<=N;i++)
    if(S[i]==S[i-1])
      n++;
    else
      if(n!=1){
	sum+=n*(n-1)/2;
	n=1;
      }
	sum+=n*(n-1)/2;
	printf("%lld\n",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&M);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^