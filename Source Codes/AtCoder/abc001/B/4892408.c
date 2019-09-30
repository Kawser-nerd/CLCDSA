int main(void)
{
	double m = 0;
	double k = 0;
	double VV =0;
	scanf("%lf", &m);
	k = m / 1000;
	if (k < 0.1) {
		VV = 0;
		printf("%02.0f\n", VV);
	}
	if (k >= 0.1 && k <= 5) {
		VV = k * 10;
		printf("%02.0f\n", VV);
	}
	if (6 <= k && k <= 30) {
		VV = k + 50;
		printf("%2.0f\n", VV);
	}
	if (35 <= k && k <= 70) {
		VV = (k - 30) / 5 + 80;
		printf("%2.0f\n", VV);
	}
	if (70 < k) {
		VV = 89;
		printf("%2.0f\n", VV);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%lf", &m);
  ^
./Main.c:6:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:10:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%02.0f\n", VV);
   ^
./Main.c:10:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:10:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:14:3: warning: incompatible implicit declaration of built-in function ‘printf’
   printf("%02.0f\n", VV);
   ^
./Main.c:14:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:18:3: warning: incompatible implicit declaration of built-in function ‘printf’
   printf("%2.0f\n", VV);
   ^
./Main.c:18:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:22:3...