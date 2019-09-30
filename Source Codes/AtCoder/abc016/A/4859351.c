#include<stdio.h>
int main(){
    int i,j;
    scanf("%d %d",&i,&j);

    if(i%j==0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&i,&j);
     ^