#include <stdio.h>
int main(void){
    int k,s,x,y,z,count=0;
    scanf("%d %d",&k,&s);
    for(x=0;x<=k;x++){
        for(y=0;y<=k;y++){
            z=s-x-y;
            if(0<=z&&z<=k) count++;
        }
    }
    printf("%d",count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&k,&s);
     ^