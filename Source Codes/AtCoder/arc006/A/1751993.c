#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j, B, p = 0, ans;
	int *E = (int *)malloc(sizeof(int) * 6);
	int *L = (int *)malloc(sizeof(int) * 6);
	for(i = 0; i < 6; i++){
		scanf("%d", &E[i]);
	}
	scanf("%d", &B);
	for(i = 0; i < 6; i++){
		scanf("%d", &L[i]);
	}
	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			if(E[i] == L[j]){
				p++;
			}
		}
	}
	if(p == 6){
		ans = 1;
	}
	else if(p == 5){
		ans = 3;
		for(i = 0; i < 6; i++){
			if(B == L[i]){
				ans--;
			}
		}
	}
	else if(p == 4){
		ans = 4;
	}
	else if(p == 3){
		ans = 5;
	}
	else{
		ans = 0;
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &E[i]);
   ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &B);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &L[i]);
   ^