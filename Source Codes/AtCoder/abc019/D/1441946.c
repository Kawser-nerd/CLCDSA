#include <stdio.h>

int main(){
	int N, a, b, c, dis, dis1, dis2;
	scanf("%d", &N);
	for(a = 1, b = 1, c = 2, dis = 0; c <= N; c++){
		printf("? %d %d\n", a, c);
		fflush(stdout);
		scanf("%d", &dis1);
		printf("? %d %d\n", b, c);
		fflush(stdout);
		scanf("%d", &dis2);
		if(dis1 >= dis2 && dis1 > dis){
			b = c;
			dis = dis1;
		}
		else if(dis2 > dis1 && dis2 > dis){
			a = c;
			dis = dis2;
		}
	}
	printf("! %d\n", dis);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &dis1);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &dis2);
   ^