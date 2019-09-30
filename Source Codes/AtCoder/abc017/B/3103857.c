c;
main(f){
	for(;(c=getchar())>10;)
	{
		if(c=='o'||c=='k'||c=='u');
		else if(c=='c'&&getchar()=='h');
		else f=0;
	}
	puts(f?"YES":"NO");
} ./Main.c:1:1: warning: data definition has no type or storage class
 c;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(f){
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘f’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:10: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
  for(;(c=getchar())>10;)
          ^
./Main.c:9:2: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  puts(f?"YES":"NO");
  ^