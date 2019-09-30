#include <stdio.h>

int main(){
    int s;scanf("%d",&s);
    int i=1;
    while(1){
        if(s==1||s==2||s==4) break;
        else{
            s=(s%2)?3*s+1:s/2;
        }   
        i++;
    }   
    printf("%d",i+3);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int s;scanf("%d",&s);
           ^