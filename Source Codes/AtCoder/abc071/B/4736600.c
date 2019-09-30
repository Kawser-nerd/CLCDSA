s[1<<17];i;main(b){for(gets(s);b&&++i<27;)b=index(s,i+96);printf(b?"None":"%c",i+96);} ./Main.c:1:1: warning: data definition has no type or storage class
 s[1<<17];i;main(b){for(gets(s);b&&++i<27;)b=index(s,i+96);printf(b?"None":"%c",i+96);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:10: warning: data definition has no type or storage class
 s[1<<17];i;main(b){for(gets(s);b&&++i<27;)b=index(s,i+96);printf(b?"None":"%c",i+96);}
          ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:12: warning: return type defaults to ‘int’ [-Wimplicit-int]
 s[1<<17];i;main(b){for(gets(s);b&&++i<27;)b=index(s,i+96);printf(b?"None":"%c",i+96);}
            ^
./Main.c: In function ‘main’:
./Main.c:1:12: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:24: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 s[1<<17];i;main(b){for(gets(s);b&&++i<27;)b=index(s,i+96);printf(b?"None":"%c",i+96);}
                        ^
./Main.c:1:45: warning: implicit declar...