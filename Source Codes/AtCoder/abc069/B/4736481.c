main(n,s)char*s;{gets(s);printf("%c%d%c",*s,n-1,s[n=strlen(s)-1]);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n,s)char*s;{gets(s);printf("%c%d%c",*s,n-1,s[n=strlen(s)-1]);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:18: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 main(n,s)char*s;{gets(s);printf("%c%d%c",*s,n-1,s[n=strlen(s)-1]);}
                  ^
./Main.c:1:26: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(n,s)char*s;{gets(s);printf("%c%d%c",*s,n-1,s[n=strlen(s)-1]);}
                          ^
./Main.c:1:26: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:26: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:1:53: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
 main(n,s)char*s;{gets(s);printf("%c%d%c",*s,n-1,s[n=strlen(s)-1]);}
                                                     ^
./Main.c...