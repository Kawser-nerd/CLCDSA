#include <stdio.h>
#define MAX_N 1<<16
long long int dp[MAX_N];
int N,M;
int G[16][16];
void print(){
  int i;
  for(i=0;i<1<<N;i++)printf("%lld ",dp[i]);
  printf("\n");
}
int main(){
  int i,j,k;
  int s,t;
  int S,v;
  int flag=1;
  scanf("%d %d",&N,&M);
  for(i=1;i<=M;i++){
    scanf("%d %d",&s,&t);
    G[s-1][t-1]=1;
  }
  dp[0]=1;
  for(S=1;S<1<<N;S++){
    for(v=0;v<N;v++){
      if(S>>v & 1){
	flag=1;
	for(i=0;i<N;i++){
	  if((S>>i & 1)==1 && (i!=v)){
	   
	    if(G[v][i]==1)flag=0;
	  }
	}
	if(flag==1)dp[S]+=dp[S&~(1<<v)];
      }
     
    }
  }
  printf("%lld\n",dp[(1<<N)-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&M);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&s,&t);
     ^