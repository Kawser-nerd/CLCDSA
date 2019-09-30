char S[1<<17],T[1<<17];
a,b,c;
main(d){
	for(scanf("%s%s%*d",S+1,T+1);S[d]|T[d];++d)
		S[d]=(S[d-1]+S[d]%4)%3,
		T[d]=(T[d-1]+T[d]%4)%3;
	for(;~scanf("%d%d%d%d",&a,&b,&c,&d);)
		puts((S[b]-S[a-1]-T[d]+T[c-1])%3?"NO":"YES");
} ./Main.c:2:1: warning: data definition has no type or storage class
 a,b,c;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a,b,c;
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 a,b,c;
     ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(d){
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%s%s%*d",S+1,T+1);S[d]|T[d];++d)
      ^
./Main.c:4:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:8: warning: incompatible implicit declaration of built-in function ‘scanf’
  for(;~scanf("%d%d%d%d",&a,&b,&c,&d);)
        ^
./Main.c:7:8: note: inc...