#include <stdio.h>
#include <stdlib.h>

int main(){
    int X,Y;
    scanf("%x%x",&X,&Y);
    
    
    if (X > Y) {
        printf(">");
    }else if(X < Y){
        printf("<");
    }else{
        printf("=");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%x%x",&X,&Y);
     ^