char s[99];i;main(){for(;~(s[i++]=getchar()););for(i-=2;putchar(s[--i]),i;);puts("");} ./Main.c:1:12: warning: data definition has no type or storage class
 char s[99];i;main(){for(;~(s[i++]=getchar()););for(i-=2;putchar(s[--i]),i;);puts("");}
            ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:14: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[99];i;main(){for(;~(s[i++]=getchar()););for(i-=2;putchar(s[--i]),i;);puts("");}
              ^
./Main.c: In function ‘main’:
./Main.c:1:35: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 char s[99];i;main(){for(;~(s[i++]=getchar()););for(i-=2;putchar(s[--i]),i;);puts("");}
                                   ^
./Main.c:1:57: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
 char s[99];i;main(){for(;~(s[i++]=getchar()););for(i-=2;putchar(s[--i]),i;);puts("");}
                                                         ^
./Main.c:1:77: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-dec...