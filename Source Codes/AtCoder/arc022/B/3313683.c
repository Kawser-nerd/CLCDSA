f,l,M[1<<17],a[1<<17];
main(m){
	for(scanf("%*d");~scanf("%d",a+f);f++){
		for(;M[a[f]];)M[a[l++]]=0;
		M[a[f]]=1;
		m=fmax(m,f-l+1);
	}
	printf("%d\n",m);
} ./Main.c:1:1: warning: data definition has no type or storage class
 f,l,M[1<<17],a[1<<17];
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 f,l,M[1<<17],a[1<<17];
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
 f,l,M[1<<17],a[1<<17];
     ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 f,l,M[1<<17],a[1<<17];
              ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(m){
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%*d");~scanf("%d",a+f);f++){
      ^
./Main.c:3:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:6: note: include ‘<stdio.h>’ or provide a declaration ...