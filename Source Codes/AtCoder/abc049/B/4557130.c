#include <stdio.h>
#include <string.h>

int main(void){
    int h,w;
    int i;
    char input[100][101];
    char img[200][101];
    scanf("%d %d",&h,&w);
    for(i=0;i<h;i++){
        scanf("%s",input[i]);
    }
    printf("\n");
    for(i=0;i<h;i++){
        strcpy(img[2 * i],input[i]);
        strcpy(img[2 * i + 1],input[i]);
    }
    for(i=0;i<2*h;i++){
        printf("%s",img[i]);
        printf("\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&h,&w);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",input[i]);
         ^