#include <stdio.h>
#include <string.h>

int main(void) {
	int a[4];
	char s[101];
	int i, j=0;
	int t;

	scanf("%s", &s);
	scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);

	t=strlen(s);

	for(i=0; i<t; i++) {
		if(i==a[j]) {
			printf("\"");
			j++;
		}
		printf("%c", s[i]);
	}
	if(a[j]==t) printf("\"");
	printf("\n");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
  scanf("%s", &s);
        ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &s);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
  ^