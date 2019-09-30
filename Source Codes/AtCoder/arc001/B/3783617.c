//
//  1_2.c
//  
//
//  Created by ??? on 2018/12/13.
//

#include <stdio.h>

int main(void)
{
    int num1,num2;
    int residual;
    int time = 0;
    
    scanf("%d %d",&num1,&num2);
    
    
    if (num1 - num2 >= 0){
        residual = num1 - num2;
    }
    else{
        residual = num2 - num1;
    }
    
    while(residual>=10){
        residual -= 10;
        time++;
    }
    if(residual == 9){
        time += 2;
    }
    else if(residual == 8){
        time += 3;
    }
    else if(residual == 7){
        time += 3;
    }
    else if(residual == 6){
        time += 2;
    }
    else if(residual == 5){
        time += 1;
    }
    else if(residual == 4){
        time += 2;
    }
    else if(residual == 3){
        time += 3;
    }
    else if(residual == 2){
        time += 2;
    }
    else if(residual == 1){
        time += 1;
    }
    
    printf("%d\n",time);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&num1,&num2);
     ^