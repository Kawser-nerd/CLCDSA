#include<stdio.h>
int main() {
	char a;
	scanf("%c",&a);
	int q;
	int w;
	int e;
	int o;
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
		printf("vowel");
	else
		printf("consonant");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&a);
  ^