#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(void){

    int girls_x, girls_y, txa, tya, txb, tyb, T, V, n, i, j;
    double L, P, length1, length2;
    int count = 0;
    
    scanf("%d%d%d%d%d%d%d",&txa, &tya, &txb, &tyb, &T, &V, &n);
    
    for(i=0; i<n; i++){
    
            scanf("%d%d",&girls_x, &girls_y);
           
            length1 = pow(abs(txa-girls_x)*abs(txa-girls_x) + abs(tya-girls_y)*abs(tya-girls_y), 0.5);
            length2 = pow(abs(txb-girls_x)*abs(txb-girls_x) + abs(tyb-girls_y)*abs(tyb-girls_y), 0.5);
            L = length1 + length2;
            P = T*V;
            if(P>=L){
                count++;
          
        }
        
    }
 
    if(count>0){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d%d",&txa, &tya, &txb, &tyb, &T, &V, &n);
     ^
./Main.c:15:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d%d",&girls_x, &girls_y);
             ^