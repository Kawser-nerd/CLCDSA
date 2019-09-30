#include<stdio.h>
int main(){
    char c1[3],c2[3];
    scanf("%s%s",c1,c2);
    if(c1[0]==c2[2]&&c1[2]==c2[0]&&c1[1]==c2[1])printf("YES\n");
    else printf("NO\n");

} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",c1,c2);
     ^