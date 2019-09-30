int main(void)
{
	int H1 = 0;
	int H2 = 0;
	scanf("%d", &H1);
	scanf("%d", &H2);
	printf("%d\n", H1-H2);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d", &H1);
  ^
./Main.c:5:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n", H1-H2);
  ^
./Main.c:7:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:7:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’