char s[1<<17];
main(){
	gets(s);
	puts(strlen(s)+(s[0]==s[strlen(s)-1])&1?"First":"Second");
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
./Main.c:4:2: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  puts(strlen(s)+(s[0]==s[strlen(s)-1])&1?"First":"Second");
  ^
./Main.c:4:7: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  puts(strlen(s)+(s[0]==s[strlen(s)-1])&1?"First":"Second");
       ^
./Main.c:4:7: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:4:7: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
/tmp/ccf1hyg4.o: In function `main':
Main.c:(.text.startup+0xc): warning: the `gets' function is dangerous and should not be used.