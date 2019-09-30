#include <stdio.h>
#include <stdlib.h>

#define int long long
#define p (int)(1e9 + 7)

signed main(){
	int N, i, ans, prev;
	scanf("%lld", &N);
	char *S1 = (char *)malloc(sizeof(char) * (N + 1));
	char *S2 = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S1);
	scanf("%s", S2);
	if(S1[0] == S2[0]){
		ans = 3;
		i = 1;
		prev = 0;
	}
	else{
		ans = 6;
		i = 2;
		prev = 1;
	}
	for(; i < N; i++){
		if(prev == 0){
			if(S1[i] == S2[i]){
				ans = (ans * 2) % p;
				prev = 0;
			}
			else{
				ans = (ans * 2) % p;
				i++;
				prev = 1;
			}
		}
		else{
			if(S1[i] == S2[i]){
				prev = 0;
			}
			else{
				ans = (ans * 3) % p;
				i++;
				prev = 1;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S1);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S2);
  ^