a;main(){gets(&a);puts(a-50?"BOWWOW":"WANWAN");} ./Main.c:1:1: warning: data definition has no type or storage class
 a;main(){gets(&a);puts(a-50?"BOWWOW":"WANWAN");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a;main(){gets(&a);puts(a-50?"BOWWOW":"WANWAN");}
   ^
./Main.c: In function ‘main’:
./Main.c:1:10: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 a;main(){gets(&a);puts(a-50?"BOWWOW":"WANWAN");}
          ^
./Main.c:1:19: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 a;main(){gets(&a);puts(a-50?"BOWWOW":"WANWAN");}
                   ^
/tmp/cccaOGID.o: In function `main':
Main.c:(.text.startup+0xc): warning: the `gets' function is dangerous and should not be used.