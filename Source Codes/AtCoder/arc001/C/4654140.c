char b[73];
g(i,d){
	return(i-=d)<0|i%9>7||b[i]&4&&g(i,d);
}
f(i,n,a){
	a=b[++i];a?a%5&g(i,1)&g(i,8)&g(i,9)&g(i,10)&&f(i,n+1,b[i]=81),b[i]=a,a&1||f(i,n):n-8?0:exit(!puts(b));
}
main(){
	f(-1,!read(0,b,72));
	exit(!puts("No Answer"));
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 g(i,d){
 ^
./Main.c: In function ‘g’:
./Main.c:2:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:1: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c: At top level:
./Main.c:5:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 f(i,n,a){
 ^
./Main.c: In function ‘f’:
./Main.c:5:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:5:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:5:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:6:89: warning: implicit declaration of function ‘exit’ [-Wimplicit-function-declaration]
  a=b[++i];a?a%5&g(i,1)&g(i,8)&g(i,9)&g(i,10)&&f(i,n+1,b[i]=81),b[i]=a,a&1||f(i,n):n-8?0:exit(!puts(b));
                                                                                         ^
./Main.c:6:89: warning: incompatible implicit declaration of built-in function ‘exit’
./Main.c:6:89: note: include ‘<stdlib.h>’ or provi...