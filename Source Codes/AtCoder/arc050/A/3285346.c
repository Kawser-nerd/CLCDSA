main(){puts(getchar_unlocked()^getchar_unlocked()^getchar_unlocked()?"No":"Yes");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){puts(getchar_unlocked()^getchar_unlocked()^getchar_unlocked()?"No":"Yes");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:8: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(){puts(getchar_unlocked()^getchar_unlocked()^getchar_unlocked()?"No":"Yes");}
        ^
./Main.c:1:13: warning: implicit declaration of function ‘getchar_unlocked’ [-Wimplicit-function-declaration]
 main(){puts(getchar_unlocked()^getchar_unlocked()^getchar_unlocked()?"No":"Yes");}
             ^