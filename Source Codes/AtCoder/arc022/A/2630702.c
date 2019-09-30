#include<stdio.h>

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

int main(void) {
	char s[262144], t[4] = "ICT", u[4] = "ict";
	int i, l,j=0;
	scanf("%s", s);
	l = strlen(s);
	for (i = 0; i < l; i++) {
		if (s[i] == t[j] || s[i] == u[j]) {
			j++;
		}
	}
	if (j == 3) { printf("YES\n"); }
	else { printf("NO\n"); }

#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:6: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  l = strlen(s);
      ^
./Main.c:11:6: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:11:6: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^