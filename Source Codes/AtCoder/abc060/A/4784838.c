#include<stdio.h>
#include<string.h>
int main(){
    char a[100],b[100],c[100];
    scanf("%s%s%s",a,b,c);
    int len1 = strlen(a),len2 = strlen(b);
    if(a[len1-1]==b[0] && b[len2-1]==c[0])printf("YES\n");
    else printf("NO\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s",a,b,c);
     ^