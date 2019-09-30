/*
AtCoder Regular Contest 005 A - ??????
Ver1
??:
*/

#include<stdio.h>
#include<string.h>

//#define DEBUG1

int main() {
	int n;
	char w[50][100];
	int cnt = 0;

	scanf("%d", &n);

	while (n--){
		scanf("%s", w);
#ifdef DEBUG1
		printf("n = %d\n", n);
		printf("w = %s\n", w);
#endif
		if (strcmp(w, "TAKAHASHIKUN")==0) { cnt++; }
		if (strcmp(w, "TAKAHASHIKUN.") == 0) { cnt++; }
		if (strcmp(w, "Takahashikun") == 0) { cnt++; }
		if (strcmp(w, "Takahashikun.") == 0) { cnt++; }
		if (strcmp(w, "takahashikun") == 0) { cnt++; }
		if (strcmp(w, "takahashikun.") == 0) { cnt++; }
	}
#ifdef DEBUG1
	printf("cnt = %d\n", cnt);
#endif
	printf("%d\n", cnt);
#ifdef DEBUG1
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   scanf("%s", w);
         ^
In file included from /usr/include/string.h:635:0,
                 from ./Main.c:8:
./Main.c:25:14: warning: passing argument 1 of ‘__builtin_strlen’ from incompatible pointer type [-Wincompatible-pointer-types]
   if (strcmp(w, "TAKAHASHIKUN")==0) { cnt++; }
              ^
./Main.c:25:14: note: expected ‘const char *’ but argument is of type ‘char (*)[100]’
./Main.c:25:14: warning: passing argument 1 of ‘__builtin_strcmp’ from incompatible pointer type [-Wincompatible-pointer-types]
   if (strcmp(w, "TAKAHASHIKUN")==0) { cnt++; }
              ^
./Main.c:25:14: note: expected ‘const char *’ but argument is of type ‘char (*)[100]’
./Main.c:25:14: warning: passing argument 1 of ‘__builtin_strlen’ from incompatible pointer type [-Wincompatible-pointer-types]
   if (strcmp(w, "TAKAHASHIKUN")==0) { cnt++; }
              ^
./Ma...