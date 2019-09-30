int main() {
	int n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = m/n; i >=1; i--) {
		if (m%i == 0) { printf("%lld", i); return 0; }
	}
} ./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%lld%lld", &n, &m);
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:3:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘int *’ [-Wformat=]
  scanf("%lld%lld", &n, &m);
        ^
./Main.c:3:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:5:19: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   if (m%i == 0) { printf("%lld", i); return 0; }
                   ^
./Main.c:5:19: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:19: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:5:26: warning: format ‘%lld’ expects argument of type ‘long lon...