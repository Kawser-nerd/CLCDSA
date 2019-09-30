#include <stdio.h>
#include <math.h>

#define MAX_a 100005
 
int isprime[MAX_a];
int add[MAX_a];
 
void eratosthenes(){
 
	int i,j;
 
	for(i=0;i<=MAX_a;i++){
		isprime[i] = 1;
	}
	isprime[0] = isprime[1] = 0;
	for(i=0;i<=sqrt((double)MAX_a)+1;i++){
		if(isprime[i]==1){
			for(j = i + i; j <= MAX_a; j+=i){
				isprime[j] = 0;
			}
		}
	}
}
int main() {

	eratosthenes();

	int i;

	for(i=3;i<=MAX_a;i++){
		if(isprime[i]==1 && isprime[(i+1)/2]==1){
		add[i]+=add[i-1]+1;
		}
		else{add[i]=add[i-1];}
	}

	int Q;

	scanf("%d",&Q);

	for(i=0;i<Q;i++){
	int l,r;
	scanf("%d %d",&l,&r);
	printf("%d\n",add[r]-add[l-1]);
	}


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&Q);
  ^
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&l,&r);
  ^
./Main.c: In function ‘eratosthenes’:
./Main.c:14:14: warning: iteration 100005u invokes undefined behavior [-Waggressive-loop-optimizations]
   isprime[i] = 1;
              ^
./Main.c:13:2: note: containing loop
  for(i=0;i<=MAX_a;i++){
  ^
./Main.c: In function ‘main’:
./Main.c:32:13: warning: iteration 100002u invokes undefined behavior [-Waggressive-loop-optimizations]
   if(isprime[i]==1 && isprime[(i+1)/2]==1){
             ^
./Main.c:31:2: note: containing loop
  for(i=3;i<=MAX_a;i++){
  ^