#include<stdio.h>
#include<ctype.h>

int main(){
    char str[13];
    int i;

    scanf("%s",str);

    str[0]=toupper(str[0]);
    for(i=1;str[i]!='\0';i++){
        str[i]=tolower(str[i]);
    }
    printf("%s\n",str);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",str);
     ^