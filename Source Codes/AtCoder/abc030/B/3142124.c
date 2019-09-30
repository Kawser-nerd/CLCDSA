n,m;double s;
main(){
	scanf("%d%d",&n,&m);
	s=((n*60-m*11)%720+720)%720;
	s/=2;
	printf("%f",s>180?360-s:s);
} ./Main.c:1:1: warning: data definition has no type or storage class
 n,m;double s;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 n,m;double s;
   ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d",&n,&m);
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%f",s>180?360-s:s);
  ^
./Main.c:6:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:6:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’