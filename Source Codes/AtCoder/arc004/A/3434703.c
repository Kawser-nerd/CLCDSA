#include <stdio.h>
#include <string.h>
#include <math.h>

int main (void){

    int n;
    int vset[200];
    int mind2;

    scanf("%d", &n);
    
    for(int i = 0; i < 2*n; i++){
        scanf("%d", vset+i);
    }

    mind2 = pow((vset[0] - vset[2]), 2) 
              + pow((vset[1] - vset[3]), 2);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
         
           int dist = pow((vset[2*i] - vset[2*j]), 2)
                        + pow((vset[2*i+1] - vset[2*j+1]), 2);
           if(dist > mind2)
             mind2 = dist;         
          
        }
    }

    printf("%f\n", sqrt(mind2));

    return 0;   
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", vset+i);
         ^