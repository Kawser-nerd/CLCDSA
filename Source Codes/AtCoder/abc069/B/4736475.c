main(n,s)char*s;{scanf("%s",s);printf("%c%d%c",*s,n-1,s[n=strlen(s)-1]);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n,s)char*s;{scanf("%s",s);printf("%c%d%c",*s,n-1,s[n=strlen(s)-1]);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:18: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(n,s)char*s;{scanf("%s",s);printf("%c%d%c",*s,n-1,s[n=strlen(s)-1]);}
                  ^
./Main.c:1:18: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:18: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:32: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(n,s)char*s;{scanf("%s",s);printf("%c%d%c",*s,n-1,s[n=strlen(s)-1]);}
                                ^
./Main.c:1:32: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:32: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:1:59: warning: implicit declaratio...