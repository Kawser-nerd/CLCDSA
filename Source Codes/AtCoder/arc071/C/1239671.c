S[1<<17],T[1<<17];
a,b,c;
main(d){
	for(scanf("%S%S%*d",S+1,T+1);S[d]|T[d];++d)
		S[d]=S[d-1]+S[d]%4,
		T[d]=T[d-1]+T[d]%4;
	for(;~scanf("%d%d%d%d",&a,&b,&c,&d);)
		puts((S[b]-S[a-1]-T[d]+T[c-1])%3?"NO":"YES");
} ./Main.c:1:1: warning: data definition has no type or storage class
 S[1<<17],T[1<<17];
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘S’ [-Wimplicit-int]
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘T’ [-Wimplicit-int]
 S[1<<17],T[1<<17];
          ^
./Main.c:2:1: warning: data definition has no type or storage class
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
  for(scanf("%S%S%*d",S+1,T+1);S[d]|T[d];++d)
      ^
./Main.c:4:6: warning: inc...