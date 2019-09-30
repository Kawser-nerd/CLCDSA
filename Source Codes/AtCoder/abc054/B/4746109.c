#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n, m;
	char **a, **b;
	scanf("%d %d", &n, &m);
	a = malloc(sizeof(char*) * n);
	b = malloc(sizeof(char*) * m);
	for(int i = 0; i < n; i++){
		a[i] = malloc(sizeof(char) * (n + 1));
		scanf("%s", a[i]);
	}
	for(int i = 0; i < m; i++){
		b[i] = malloc(sizeof(char) * (m + 1));
		scanf("%s", b[i]);
	}

	for(int i = 0; i < n - m + 1; i++){
		for(int j = 0; j < n - m + 1; j++){
			for(int k = 0; k < m; k++){
				if(strncmp(a[i + k] + j, b[k], m))break;
				if(k == m - 1){
					printf("Yes\n");
					return 0;
				}
			}
		}
	}
	printf("No\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &m);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", a[i]);
   ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", b[i]);
   ^