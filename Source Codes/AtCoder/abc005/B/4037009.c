#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    
    int t[n];
    
    for(int i=0; i<n; i++){
        scanf("%d", &t[i]);
    }
    
    int min=t[0];
    for(int i=1; i<n; i++){
        min = (min > t[i])? t[i] : min;
    }
    
    printf("%d\n", min);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &t[i]);
         ^