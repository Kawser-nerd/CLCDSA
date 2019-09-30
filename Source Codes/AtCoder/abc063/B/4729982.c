c[999];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");} ./Main.c:1:1: warning: data definition has no type or storage class
 c[999];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:8: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c[999];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");}
        ^
./Main.c: In function ‘main’:
./Main.c:1:8: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:25: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 c[999];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");}
                         ^
./Main.c:1:48: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 c[999];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");}
                                                ^