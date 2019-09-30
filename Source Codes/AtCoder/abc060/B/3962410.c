#include<stdio.h>
int main()
{
    int a,b,c ;
    scanf ("%d%d%d",&a,&b,&c) ;
    for (int i=1; i>0; i++){
        if (a*i%b==c) {
            printf ("YES\n") ;
            exit (0) ;
        }
        if (i>1 && a*i%b==a%b){
            printf ("NO\n") ;
            exit (0) ;
        }
    }
    return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:13: warning: implicit declaration of function ‘exit’ [-Wimplicit-function-declaration]
             exit (0) ;
             ^
./Main.c:9:13: warning: incompatible implicit declaration of built-in function ‘exit’
./Main.c:9:13: note: include ‘<stdlib.h>’ or provide a declaration of ‘exit’
./Main.c:13:13: warning: incompatible implicit declaration of built-in function ‘exit’
             exit (0) ;
             ^
./Main.c:13:13: note: include ‘<stdlib.h>’ or provide a declaration of ‘exit’
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%d%d%d",&a,&b,&c) ;
     ^