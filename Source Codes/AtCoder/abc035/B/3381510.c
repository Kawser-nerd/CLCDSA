#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    char data[100000];
    scanf("%s",&data[0]);
    int size;
    size = strlen(data);
    int x = 0,y = 0,z = 0,i;
    for(i = 0;i<size;i++){
        if(data[i] == 'U'){
            y++;
        }else if(data[i] == 'D'){
            y--;
        }else if(data[i] == 'R'){
            x++;
        }else if(data[i] == 'L'){
            x--;
        }else{
            z++;
        }
    }
    int ans = abs(x) + abs(y);
    int max,min;
    max = ans + abs(z);
    if(ans < z && (ans % 2 == abs(z) % 2)){
        min = 0;
    }else if(ans < z && (ans % 2 != abs(z) % 2)){
        min = 1;
    }else{
        min = ans - abs(z);
    }
    scanf("%d",&ans);
    if(ans == 1){
        printf("%d\n",max);
    }else{
     printf("%d\n",min);
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&data[0]);
     ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&ans);
     ^