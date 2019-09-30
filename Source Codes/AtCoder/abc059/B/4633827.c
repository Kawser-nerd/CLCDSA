#include <stdio.h>
#include <string.h>
int main(void){
    char a[102],b[102];
    int i;
    scanf("%s%s",a,b);
    if(strlen(a)>strlen(b)){
        printf("GREATER\n");
        return 0;
    }
    if(strlen(a)<strlen(b)){
        printf("LESS\n");
        return 0;
    }
    if(strlen(a)==strlen(b)){
        for(i=0;i<strlen(a);i++){
            if(a[i]>b[i]){
                printf("GREATER\n");
                return 0;
            }
            if(a[i]<b[i]){
                printf("LESS\n");
                return 0;
            }
        }
        printf("EQUAL\n");
        return 0;
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",a,b);
     ^