#include <stdio.h>
#include <stdlib.h>

int main(){
    int A, B, n, m;
    scanf("%d %d", &A, &B);
    n = abs(A-B)/10;
    m = abs(A-B)%10;
    
    switch(m){
        case 0: break;
        case 1: n++; break;
        case 2: n += 2; break;
        case 3: n += 3; break;
        case 4: n += 2; break;
        case 5: n += 1; break;
        case 6: n += 2; break;
        case 7: n += 3; break;
        case 8: n += 3; break;
        case 9: n += 2; break;
    }   

    printf("%d\n", n); 

return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &A, &B);
     ^