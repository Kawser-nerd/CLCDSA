#include <stdio.h>
#include <stdlib.h>

int day(int m, int d){
	if(m == 1){
		return d;
	}
	else if(m == 2){
		return 31 + d;
	}
	else if(m == 3){
		return 60 + d;
	}
	else if(m == 4){
		return 91 + d;
	}
	else if(m == 5){
		return 121 + d;
	}
	else if(m == 6){
		return 152 + d;
	}
	else if(m == 7){
		return 182 + d;
	}
	else if(m == 8){
		return 213 + d;
	}
	else if(m == 9){
		return 244 + d;
	}
	else if(m == 10){
		return 274 + d;
	}
	else if(m == 11){
		return 305 + d;
	}
	else if(m ==12){
		return 335 + d;
	}
}

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, m, d, i, D;
	scanf("%d", &N);
	int *a = (int *)malloc(sizeof(int) * 400);
	for(i = 0; i < 400; i++){
		if(i % 7 == 0 || i % 7 == 6){
			a[i] = 1;
		}
		else{
			a[i] = 0;
		}
	}
	for(i = 0; i < N; i++){
		scanf("%d/%d", &m, &d);
		D = day(m, d) - 1;
		while(a[D] == 1){
			D++;
		}
		a[D] = 1;
	}
	int now = 0, ans = 0;
	for(i = 0; i < 366; i++){
		if(a[i] == 0){
			now = 0;
		}
		else{
			now++;
		}
		ans = max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:60:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d/%d", &m, &d);
   ^