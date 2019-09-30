#include<stdio.h>
int main(void) {
	int num, ng1, ng2, ng3, i;
	scanf("%d%d%d%d", &num, &ng1, &ng2, &ng3);

	if (num == ng1 || num == ng2 || num == ng3) {
		puts("NO");
		return 0;
	}

	for (i = 0; i < 100; i++) {
		if (num - 3 != ng1 && num - 3 != ng2 && num - 3 != ng3&&num-3>=0) {
			num -= 3;
		}
		else if (num - 2 != ng1 && num - 2 != ng2 && num - 2 != ng3&&num-2>=0) {
			num -= 2;
		}
		else if (num - 1 != ng1 && num - 1 != ng2 && num - 1 != ng3&&num-1>=0) {
			num -= 1;
		}
		if (num == 0) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &num, &ng1, &ng2, &ng3);
  ^