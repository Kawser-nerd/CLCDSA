#include <stdio.h>
#include <string.h>

int main(void){
    int g=0,p=0;
    char s[100020];
    scanf("%s",s);
    for (int i=0; i<strlen(s); i++){
        if (s[i]=='g'){
            g++;
        } else if (s[i]=='p'){
            p++;
        }
    }
    if ((g+p)/2==p){
        printf("0\n");
    } else {
        printf("%d\n",(g+p)/2-p);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^