char s[99];i;main(a){for(;~(a=getchar());)a-66?s[i++]=a:i>0?s[--i]=0:0;puts(s);} ./Main.c:1:12: warning: data definition has no type or storage class
 char s[99];i;main(a){for(;~(a=getchar());)a-66?s[i++]=a:i>0?s[--i]=0:0;puts(s);}
            ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:14: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[99];i;main(a){for(;~(a=getchar());)a-66?s[i++]=a:i>0?s[--i]=0:0;puts(s);}
              ^
./Main.c: In function ‘main’:
./Main.c:1:14: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:31: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 char s[99];i;main(a){for(;~(a=getchar());)a-66?s[i++]=a:i>0?s[--i]=0:0;puts(s);}
                               ^
./Main.c:1:72: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 char s[99];i;main(a){for(;~(a=getchar());)a-66?s[i++]=a:i>0?s[--i]=0:0;puts(s);}
                                                                        ^