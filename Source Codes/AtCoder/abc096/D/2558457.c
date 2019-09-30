#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_a 300000

int isprime[MAX_a];
int prime[MAX_a];

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

	int i,j;

	eratosthenes();

	int cnt=0;

	for(i=1;i<=55555;i++){
		if(isprime[i] == 1){
			prime[cnt]=i;
			cnt++;
		}
	}

	int N;

	scanf("%d",&N);

	int m,x1;

	int cnt2;

	int ans[60];

	for(m=1;m<cnt;m++){
		memset(ans,0,sizeof(ans));
		ans[0]=2;
		cnt2=1;
		for(x1=5;;x1+=5){
			if(prime[m]+(2*x1)>=MAX_a){return 0;}
			if(isprime[prime[m]+(2*x1)]==1){
				ans[cnt2]=prime[m]+(2*x1);
				cnt2++;
				if(cnt2==N){
					for(j=0;j<N-1;j++){
					printf("%d ",ans[j]);
					}
					printf("%d\n",ans[N-1]);
					return 0;
				}
			}

		}
	}

		return 0;
	} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c: In function ‘eratosthenes’:
./Main.c:15:14: warning: iteration 300000u invokes undefined behavior [-Waggressive-loop-optimizations]
   isprime[i] = 1;
              ^
./Main.c:14:2: note: containing loop
  for(i=0;i<=MAX_a;i++){
  ^