#include <stdio.h>

int main(){
    char b;
    b=getchar();
    if (b=='A'){
        printf("T\n");
    }else if(b=='T'){
        printf("A\n");
    }else if(b=='G'){
        printf("C\n");
    }else if(b=='C'){
        printf("G\n");
    }
    return 0;
}