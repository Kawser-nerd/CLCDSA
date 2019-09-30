#include <stdio.h>

int main(void){
	int prime[100001]={0};
	
	for(int i=2;i<=100001;i++){
		if(prime[i] == 0){
			prime[i] = 1;
			for(int j=i+i;j<=100001;j+=i){
				prime[j] = -1;
			}
		}
	}
	
	int c[100002]={0};
	for(int i=1;i<=100001;i+=2){
		if(prime[i]==1 && prime[(i+1)/2]==1)c[i]=1;
	}
	
	for(int i=1;i<=100002;i++){
		if(c[i]>=1)c[i] = c[i-1]+1;
		else c[i] = c[i-1];
	}
	
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",c[r]-c[l-1]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&Q);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&l,&r);
   ^
./Main.c:21:7: warning: iteration 100001u invokes undefined behavior [-Waggressive-loop-optimizations]
   if(c[i]>=1)c[i] = c[i-1]+1;
       ^
./Main.c:20:2: note: containing loop
  for(int i=1;i<=100002;i++){
  ^
./Main.c:17:11: warning: iteration 50000u invokes undefined behavior [-Waggressive-loop-optimizations]
   if(prime[i]==1 && prime[(i+1)/2]==1)c[i]=1;
           ^
./Main.c:16:2: note: containing loop
  for(int i=1;i<=100001;i+=2){
  ^
./Main.c:7:11: warning: iteration 99999u invokes undefined behavior [-Waggressive-loop-optimizations]
   if(prime[i] == 0){
           ^
./Main.c:6:2: note: containing loop
  for(int i=2;i<=100001;i++){
  ^