long n,k,c,b;
main(){
	scanf("%d%d",&n,&k);n++;
	for(b=k;++b<n;){
		c+=n/b*(b-k)-!k;
		c+=fdim(n,n/b*b+k);
	}
	printf("%ld",c);
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d",&n,&k);n++;
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:3:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
  scanf("%d%d",&n,&k);n++;
        ^
./Main.c:3:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long int *’ [-Wformat=]
./Main.c:6:6: warning: implicit declaration of function ‘fdim’ [-Wimplicit-function-declaration]
   c+=fdim(n,n/b*b+k);
      ^
./Main.c:6:6: warning: incompatible implicit declaration of built-in function ‘fdim’
./Main.c:6:6: note: include ‘<math.h>’ or provide a declaration of ‘fdim’
./Main.c:8:2: warning: implicit declaration of function ‘...