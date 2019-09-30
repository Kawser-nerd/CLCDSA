#include<stdio.h>
#include<string.h>

int main(){
    char a[11];
    int len;
    char c;

    scanf("%s",a);
    len = strlen(a);
    if(a[1]=='\0'){
        if(a[0]=='a'){
            printf("-1\n");
        }else{ 
            c = a[0] - 0x01;
            printf("%c\n",c);
        }
    }else{ 
        a[len-1] = '\0';
        printf("%s\n",a); 
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a);
     ^