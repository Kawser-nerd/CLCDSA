main(n,m,a,b,c,i){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(i=1;i<=m;i++){
		if(n<=a)n+=b;
		scanf("%d",&c);
		if(n<c){printf("%d\n",i);exit(0);}
		n-=c;
	}
	puts("complete");
	exit(0);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n,m,a,b,c,i){
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d%d%d",&n,&m,&a,&b);
  ^
./Main.c:2:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:2:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:11: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   if(n<c){printf("%d\n",i);exit(0);}
           ^
./Main.c:6:11: warning: incomp...