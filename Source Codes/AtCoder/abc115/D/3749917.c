long n, k;

long fun(long n, long x){
	if (n == 0)return (x <= 0 ? 0 : 1);
	long p = (1LL << n) - 1;
	if (x <= 2*p)return fun(n - 1, x - 1);
	return p + 1 + fun(n - 1, x - 1 - 2*p);
}

int main(){
	scanf("%ld%ld",&n,&k);
	printf("%ld\n",fun(n, k));
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%ld%ld",&n,&k);
  ^
./Main.c:11:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:11:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:12:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%ld\n",fun(n, k));
  ^
./Main.c:12:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:12:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’