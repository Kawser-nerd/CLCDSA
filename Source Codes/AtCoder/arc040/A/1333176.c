#include <stdio.h>

int main(void){
    int n;
    int i;
    int j;
    int r = 0;
    int b = 0;
    
    scanf("%d", &n);
    char s[100][100] = {};
    
    for( i = 0; i < n; ++i){
        scanf("%s", s[i]);
    }
    
    for( i = 0; i < n; ++i){
        for( j = 0; j < n; ++j){
            if( s[i][j] == 'R'){
                ++r;
            }else if( s[i][j] == 'B'){
                ++b;
            }
        }
    }
    
    if( r > b){
        printf("TAKAHASHI\n");
    }else if( r < b){
        printf("AOKI\n");
    }else{
        printf("DRAW\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s[i]);
         ^