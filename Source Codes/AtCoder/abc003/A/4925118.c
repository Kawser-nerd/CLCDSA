int main(void)
{
	int n;
	int wa=0;

	scanf("%d",&n);

	for (int i = 1; i <= n; i++) {

		wa += i;
	}
	
	printf("%d", wa*10000/n);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d",&n);
  ^
./Main.c:6:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:13:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d", wa*10000/n);
  ^
./Main.c:13:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:13:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’