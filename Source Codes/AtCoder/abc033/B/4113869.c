#include <stdio.h>
#include <string.h>

int main(void){
	char name[25], in[25];
	int max = 0, sum = 0, n, no;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %d", in, &no);
		if(no > max){
			strcpy(name, in);
			max = no;
		}
		sum += no;
	}
	if(sum / 2 < max)
		printf("%s\n", name);
	else
		printf("atcoder\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %d", in, &no);
   ^