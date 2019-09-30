#include "stdio.h"

int main(){
    
    int A,B,C;
    int A_temp,B_temp,C_temp;
    
    scanf("%d %d %d",&A,&B,&C);
    int roomcounter=0;
    while (1)
    {
        
        if ((A%2==1)||(B%2==1)||(C%2==1)) {
            break;
        }
        
        if (A==B) {
            if (A==C) {
            if (B==C) {
            roomcounter=-1;
            break;
            }}}
        
        A_temp=A;
        B_temp=B;
        C_temp=C;
        
        A=0;
        B=0;
        C=0;
        
        A+=B_temp/2+C_temp/2;
        B+=A_temp/2+C_temp/2;
        C+=A_temp/2+B_temp/2;
        
        roomcounter++;
        
        
    }
    
    printf("%d\n",roomcounter);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A,&B,&C);
     ^