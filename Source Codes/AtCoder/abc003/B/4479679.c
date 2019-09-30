#include <stdio.h>
#include <string.h>
int main(void){
    // Your code here!
    char s[31],t[31],x[31];
    char str[] = {"@a@t@c@o@d@e@r@"};
    int sw=0;
    scanf("%s",s);
    scanf("%s",t);
    for(int i=0;s[i]!='\0';i++){
        sprintf(x,"%c%c",s[i],t[i]);
        if(s[i]!=t[i] && strstr(str,x)==NULL)
            sw = 1;
    }
    if(sw==0)
        printf("You can win\n");
    else
        printf("You will lose\n");
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",t);
     ^