#include<stdio.h>

int main(void){
	int N,M,i,j,sum=0;
	scanf("%d%d",&N,&M);
	int l[N],r[N],s[N],arr[M];
	for(i=0;i<N;i++){
		scanf("%d%d%d",&l[i],&r[i],&s[i]);
		sum+=s[i];
	}
	for(i=0;i<M;i++) arr[i]=0;
	
	for(i=0;i<N;i++){
		arr[l[i]-1]+=s[i];
		arr[r[i]]-=s[i];
	}
	for(i=1;i<M;i++) arr[i]+=arr[i-1];
	
	int min=sum;
	for(i=0;i<M;i++){
		if(min>arr[i]) min=arr[i];
	}
	
	printf("%d\n",sum-min);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&M);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&l[i],&r[i],&s[i]);
   ^