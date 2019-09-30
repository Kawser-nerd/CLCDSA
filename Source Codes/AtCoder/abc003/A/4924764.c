int main(void)
{
	int a;
	int sum=0;
	int ave = 0;
	int x = 10000;
	scanf("%d", &a);
	for (int i = 1;i < a+1;i++) {
		sum +=x*i;
	}
	ave = sum / a;
	printf("%d\n", ave);
	
	return 0;
     
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d", &a);
  ^
./Main.c:7:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:7:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:12:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n", ave);
  ^
./Main.c:12:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:12:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’