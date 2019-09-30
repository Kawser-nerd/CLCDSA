c[];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");} ./Main.c:1:1: warning: data definition has no type or storage class
 c[];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c[];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:22: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 c[];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");}
                      ^
./Main.c:1:45: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 c[];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");}
                                             ^
./Main.c: At top level:
./Main.c:1:1: warning: array ‘c’ assumed to have one element
 c[];main(a){for(;~(a=getchar());)*c+=c[a]++;puts(*c?"no":"yes");}
 ...