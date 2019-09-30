#define g getchar()
main(){puts(g+g-g?"No":"Yes");} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){puts(g+g-g?"No":"Yes");}
 ^
./Main.c: In function ‘main’:
./Main.c:2:8: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(){puts(g+g-g?"No":"Yes");}
        ^
./Main.c:1:11: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 #define g getchar()
           ^
./Main.c:2:13: note: in expansion of macro ‘g’
 main(){puts(g+g-g?"No":"Yes");}
             ^