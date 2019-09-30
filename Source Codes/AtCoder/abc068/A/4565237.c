#include<stdio.h>
main(i){scanf("%d",&i);printf("ABC%d",i);} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i){scanf("%d",&i);printf("ABC%d",i);}
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 main(i){scanf("%d",&i);printf("ABC%d",i);}
         ^