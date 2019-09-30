char p;
t,c,x,y;
main(){
	for(;(p=getchar_unlocked())>10;){
		x+=(p=='R')-(p=='L');
		y+=(p=='U')-(p=='D');
		c+=p=='?';
	}
	x=abs(x);
	y=abs(y);
	printf("%d\n",getchar_unlocked()=='1'?x+y+c:x+y>=c?x+y-c:(c-x-y)&1);
} ./Main.c:2:1: warning: data definition has no type or storage class
 t,c,x,y;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 t,c,x,y;
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 t,c,x,y;
     ^
./Main.c:2:7: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 t,c,x,y;
       ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:10: warning: implicit declaration of function ‘getchar_unlocked’ [-Wimplicit-function-declaration]
  for(;(p=getchar_unlocked())>10;){
          ^
./Main.c:9:4: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
  x=abs(x);
    ^
./Main.c:11:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n",getchar_unlocked()=='1'?x+y+c:x+y>=c?x+y-c:(c...