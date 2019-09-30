#include <stdio.h>

main() {
	char a[20];
	int i = 0;
	int j = 0;
	scanf("%s", &a);

	while (a[i] != '\0') {
		if (a[i] >= '0' && a[i] <= '9') {
			printf("%c", a[i]);
			if (a[i + 1] >= '0' && a[i + 1] <= '9') {
				printf("%c\n", a[i + 1]);
				break;
			}
			else {
				printf("\n");
				break;
			}
		}
		i++;
	}
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main() {
 ^
./Main.c: In function ‘main’:
./Main.c:7:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[20]’ [-Wformat=]
  scanf("%s", &a);
        ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &a);
  ^