s[9],t[9];M,v,a;
main(){
	for(gets(t);~scanf("%s%d",t,&a);v+=a)a>M&&(M=a,strcpy(s,t));
	puts(M*2>v?s:"atcoder");
} ./Main.c:1:1: warning: data definition has no type or storage class
 s[9],t[9];M,v,a;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:6: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 s[9],t[9];M,v,a;
      ^
./Main.c:1:11: warning: data definition has no type or storage class
 s[9],t[9];M,v,a;
           ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘v’ [-Wimplicit-int]
 s[9],t[9];M,v,a;
             ^
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 s[9],t[9];M,v,a;
               ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:6: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  for(gets(t);~scanf("%s%d",t,&a);v+=a)a>M&&(M=a,strcpy(s,t));
      ^
./Main.c:3:15: warning: im...