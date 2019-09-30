#import<stdio.h>
main(long x){scanf("%ld",&x);printf("%ld",x/11*2+(x%11+5)/6);} ./Main.c:1:2: warning: #import is a deprecated GCC extension [-Wdeprecated]
 #import<stdio.h>
  ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(long x){scanf("%ld",&x);printf("%ld",x/11*2+(x%11+5)/6);}
 ^
./Main.c: In function ‘main’:
./Main.c:2:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 main(long x){scanf("%ld",&x);printf("%ld",x/11*2+(x%11+5)/6);}
              ^