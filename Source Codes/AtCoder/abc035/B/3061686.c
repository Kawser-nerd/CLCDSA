buf[30000];char*p=buf;
t,c,x,y;
main(){
	read(0,buf,100010);
	for(;*p>10;p+=1){
		x+=(*p=='R')-(*p=='L');
		y+=(*p=='U')-(*p=='D');
		c+=*p=='?';
	}
	p+=1;
	x=abs(x);
	y=abs(y);
	printf("%d\n",*p=='1'?x+y+c:x+y>=c?x+y-c:(c-x-y)&1);
} ./Main.c:1:1: warning: data definition has no type or storage class
 buf[30000];char*p=buf;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘buf’ [-Wimplicit-int]
./Main.c:1:19: warning: initialization from incompatible pointer type [-Wincompatible-pointer-types]
 buf[30000];char*p=buf;
                   ^
./Main.c:2:1: warning: data definition has no type or storage class
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
./Main.c:4:2: warning: implicit declaration of function ‘read’ [-Wimplicit-function-declaration]
  read(0...