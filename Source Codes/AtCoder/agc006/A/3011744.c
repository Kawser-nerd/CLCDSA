#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[101],t[101];
    int n,i,j;
    scanf("%d%s%s",&n,s,t);
    for(i=strlen(s);i>0;i--){
        for(j=0;i>j;j++)if(s[strlen(s)-i+j]!=t[j])break;
        if(j==i)break;
    }
    printf("%d",strlen(s)*2-i);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:12: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘size_t {aka long unsigned int}’ [-Wformat=]
     printf("%d",strlen(s)*2-i);
            ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%s%s",&n,s,t);
     ^