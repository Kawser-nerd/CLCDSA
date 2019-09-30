#include <stdio.h>

int main(void){
    char post[11];
    int a,b;
    scanf ("%d %d",&a,&b);
    scanf ("%s",post);
    int i;
    for(i = 0;i<a;i++){
        if(!(post[i] >= '0' && post[i] <= '9')){
            printf("No\n");
            return 0;
        }
        if(post[a]!= '-'){
            printf("No\n");
            return 0;
        }

    }

    for(i = a+1;i<a+b;i++){
        if(!(post[i] >= '0' && post[i] <= '9')){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%d %d",&a,&b);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%s",post);
     ^