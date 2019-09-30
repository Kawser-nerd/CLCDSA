#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
	return strcmp(*(char**)a, *(char**)b);
}

int main(void){
	char **str;
	int n, l;
	scanf("%d %d", &n, &l);
	str = malloc(sizeof(char*) * n);
	for(int i = 0; i < n; i++){
		str[i] = malloc(sizeof(char) * (l + 5));
		scanf("%s", str[i]);
	}
	qsort(str, n, sizeof(char*), cmp);
	for(int i = 0; i < n; i++)
		printf("%s", str[i]);
	putchar('\n');
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &l);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str[i]);
   ^