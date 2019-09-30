main() {
	double h, b;
	scanf("%lf%lf",&h,&b);
	h /= 100;
	printf("%lf\n", b*h*h);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main() {
 ^
./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%lf%lf",&h,&b);
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%lf\n", b*h*h);
  ^
./Main.c:5:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’