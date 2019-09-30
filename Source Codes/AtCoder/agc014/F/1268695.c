q[1<<18];i,n;
main(a){
	for(;~scanf("%d",&a);)n?q[a]=++i:(n=a);
	for(a=0;--i;a?q[n]<q[i]^q[i]<q[i+1]^q[i+1]<q[n]?a++,n=i+1:0:q[i]<q[i+1]?n--:a++);
	printf("%d",a);
} ./Main.c:1:1: warning: data definition has no type or storage class
 q[1<<18];i,n;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘q’ [-Wimplicit-int]
./Main.c:1:10: warning: data definition has no type or storage class
 q[1<<18];i,n;
          ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
 q[1<<18];i,n;
            ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:8: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(;~scanf("%d",&a);)n?q[a]=++i:(n=a);
        ^
./Main.c:3:8: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:8: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:2: warning: implicit declaration of function ...