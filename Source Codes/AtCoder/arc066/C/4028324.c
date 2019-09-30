long a,b,c;o;
main(A){
	b=c=-1e18;
	for(scanf("%*d%ld",&a);~scanf(" %c%d",&o,&A);)
		b=o%3?a+=A,fmax(b-A,c+=A):(a=fmax(a-A,c=b+A));
	printf("%ld",a);
} ./Main.c:1:12: warning: data definition has no type or storage class
 long a,b,c;o;
            ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘o’ [-Wimplicit-int]
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(A){
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘A’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%*d%ld",&a);~scanf(" %c%d",&o,&A);)
      ^
./Main.c:4:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:4:32: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
  for(scanf("%*d%ld",&a);~scanf(" %c%d",&o,&A);)
                                ^
./Main.c:5:14: warning: implicit declaration of function ‘fmax’ [-Wimplicit-function-declaration]
   b=o%3?a+=A,fmax(b-A,c+=A):(a=fmax(a-A...