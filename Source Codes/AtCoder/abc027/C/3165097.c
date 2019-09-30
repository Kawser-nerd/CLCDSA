#include <stdio.h>

typedef long long ll;

int main(){

	ll N;
	scanf("%lld",&N);

	int hit=0;

	ll k=1ll;

	while(1){
		if(k<=N&&N<=(2ll*k)-1){break;}
		k*=2ll;
		hit++;
	}

	ll x=1ll;

	int turn=0;

	int ans;

	if(hit%2==0){
		while(1){

			if(turn%2==0){
				x=(2ll*x)+1ll;
				if(x>N){
					ans=1;//takahashi???
					break;
				}
			}
			else{
				x=2ll*x;
				if(x>N){
					ans=0;//aoki???
					break;
				}
			}
			turn++;
		}
	}
	else{
	while(1){
			if(turn%2==0){
				x=2ll*x;
				if(x>N){
					ans=1;//takahashi???
					break;
				}
			}
			else{
				x=(2ll*x)+1ll;
				if(x>N){
					ans=0;//aoki???
					break;
				}
			}
			turn++;
		}
	}

	if(ans==0){printf("Takahashi\n");}
	else{printf("Aoki\n");}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&N);
  ^