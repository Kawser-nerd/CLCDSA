char a[];main(){gets(a);puts(a[strlen(a)-1]-'T'?"NO":"YES");} ./Main.c:1:10: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char a[];main(){gets(a);puts(a[strlen(a)-1]-'T'?"NO":"YES");}
          ^
./Main.c: In function ‘main’:
./Main.c:1:17: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 char a[];main(){gets(a);puts(a[strlen(a)-1]-'T'?"NO":"YES");}
                 ^
./Main.c:1:25: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 char a[];main(){gets(a);puts(a[strlen(a)-1]-'T'?"NO":"YES");}
                         ^
./Main.c:1:32: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
 char a[];main(){gets(a);puts(a[strlen(a)-1]-'T'?"NO":"YES");}
                                ^
./Main.c:1:32: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:1:32: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c: At top level:
./Main.c:1:6: warning: array ‘a’ assumed to have one element
 char a[];main(){gets(a);puts(a...