#include <stdio.h>
#include <stdlib.h>
int min(int a,int b,int c,int d){
	int min =a;
	if(min>b)min=b;
	if(min>c)min=c;
	if(min>d)min=d;
	return min;
}
int main(void){
	int N,A,B,C;
	int tempA,tempB,tempC;
	int l[8]={};
	int i,j;
	scanf("%d%d%d%d",&N,&A,&B,&C);
	for(i=0;i<N;i++){
		scanf("%d",&l[i]);
	}
	int function(int a,int b,int c,int d,int n,int l[8]){
		if(d==n && a*b*c>0){
			return abs(A-a)+abs(B-b)+abs(C-c) -30;
		}else if(d==n){
			return 1e9;
		}
		else{
			int r1 = function(a,b,c,d+1,n,l);
			int r2 = function(a+l[d],b,c,d+1,n,l)+10;
			int r3 = function(a,b+l[d],c,d+1,n,l)+10;
			int r4 = function(a,b,c+l[d],d+1,n,l)+10;
			return min(r1,r2,r3,r4);
		}
	}
	int ans = function(0,0,0,0,N,l);
	printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&N,&A,&B,&C);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&l[i]);
   ^