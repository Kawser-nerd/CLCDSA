char m[55][55];i,j;
main(n){
	scanf("%d\n",&n);
	for(;gets(m[i++]););
	for(;j<n;j++){
      putchar(32);
		for(i=n;i--;)putchar(m[i][j]);
	}
} ./Main.c:1:16: warning: data definition has no type or storage class
 char m[55][55];i,j;
                ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 char m[55][55];i,j;
                  ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n){
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d\n",&n);
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:4:7: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  for(;gets(m[i++]););
       ^
./Main.c:6:7: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
  ...