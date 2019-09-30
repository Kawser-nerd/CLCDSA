int main(void)
{
	int x, y;
	scanf("%d %d", &x, &y);
	if (x < y) {
		printf("%d\n", y);
	}
	else {
		printf("%d\n", x);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d %d", &x, &y);
  ^
./Main.c:4:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", y);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:9:3: warning: incompatible implicit declaration of built-in function ‘printf’
   printf("%d\n", x);
   ^
./Main.c:9:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’