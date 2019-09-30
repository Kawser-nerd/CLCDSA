int main() {
	long long int n, m, sosu[200005] = {}, count[200005] = {}, L[200005],R[200005];
	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &L[i], &R[i]);
	}

	for (int i = 2; i <= 100000; i++) {
		if (sosu[i] == 0) {
			for (int j = 2 * i; j <= 100000; j += i) {
				sosu[j] = -1;
			}
		}
	}

	for (int i = 2; i <= 100000; i++) {
		if (sosu[i] == 0&&sosu[(i+1)/2]==0&&i%2==1) {
			count[i] = count[i - 1] + 1;
         
		}else{
		count[i] = count[i - 1];
        }
	}
	for (int i = 0; i < n; i++) {
		printf("%lld\n",count[R[i]]-count[L[i]-1]);
	}
} ./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%lld", &n);
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:26:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%lld\n",count[R[i]]-count[L[i]-1]);
   ^
./Main.c:26:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:26:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’