#include <stdio.h>
#include <stdlib.h>

long long min,max;
void best(long long left1,long long right1,long long k){
	long long left = left1 + 1;
	long long right = right1 - 1;
	long long N = right1 - 1;
	min = (N-1) / 2;
	max = N/2;
	while (left<=right){
		//printf("left: %llu , right: %llu, k: %llu\n",left,right,k);
		if (k==1){
			min = (right-left) / 2;
			max = (right - left + 1) / 2;
			return;
		}
		if (k==(right-left + 1)){
			min = 0;
			max = 0;
			return;
		}
		if (k%2==1){
			long long mid = left + (right-left) / 2;
			right = mid - 1;
			k = k/2;
		}else{
			if (k==2){
				left = left + (right-left)/2 + 1; 
				k--;
			}
			else{
				long long mid = left + (right-left)/2;
				if ((right-left)/2*2 == right - left)
					right = mid - 1;
				else
					right = mid;
				k = k/2;
			}
			
		}
	}
}

int main(){
	int T,i;
	scanf("%d", &T);
	for (i=1;i<=T;i++){
		long long N,K;
		scanf("%llu %llu" , &N , &K);
		best(0,N+1,K);
		printf("Case #%d: %llu %llu\n", i, max, min);
	}
	return 0;
}