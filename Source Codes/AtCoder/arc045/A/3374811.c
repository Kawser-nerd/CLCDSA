#include <stdio.h>
#include <string.h>
int main(void){
    int count=0;
    char s[120],p[2];
    for (int i=0; i<2000; i++){
        scanf("%c",&p[0]);
        if (p[0]=='L'){
            s[count]='<';
            count++;
        } else if (p[0]=='R'){
            s[count]='>';
            count++;
        } else if (p[0]=='A'){
            s[count]='A';
            count++;
        } else if (p[0]==' '){
            s[count]=' ';
            count++;
        }
    }
s[count]='\0';
    printf("%s\n",s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c",&p[0]);
         ^