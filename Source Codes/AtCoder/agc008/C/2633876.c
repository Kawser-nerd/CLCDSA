main(I,O,J,L,d){
	scanf("%d%d%*d%d%d",&I,&O,&J,&L);
	printf("%lld",(long long)O+I+J+L-(I&&J&&L?(d=I%2+J%2+L%2)>1?3-d:d:I%2+J%2+L%2));
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(I,O,J,L,d){
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘I’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘O’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘J’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘L’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d%*d%d%d",&I,&O,&J,&L);
  ^
./Main.c:2:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:2:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:3:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%lld",(long long)O+I+J+L-(I&&J&&L?(d=I%2+J%2+L%2)>1?3-d:d:I%2+J%2+L%2));
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-i...