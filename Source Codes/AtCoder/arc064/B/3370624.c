char s[1<<17];
main(){
	read(0,s,1<<17);
	puts(strlen(s)+(s[0]==s[strlen(s)-2])&1?"Second":"First");
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘read’ [-Wimplicit-function-declaration]
  read(0,s,1<<17);
  ^
./Main.c:4:2: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  puts(strlen(s)+(s[0]==s[strlen(s)-2])&1?"Second":"First");
  ^
./Main.c:4:7: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  puts(strlen(s)+(s[0]==s[strlen(s)-2])&1?"Second":"First");
       ^
./Main.c:4:7: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:4:7: note: include ‘<string.h>’ or provide a declaration of ‘strlen’