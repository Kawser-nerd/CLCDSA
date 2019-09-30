#include <stdio.h>
int main(void){
    int left=0,right=0;
    int n,i;
    char s[101];
    scanf("%d %s",&n,s);
    for(i=0;i<n;i++){
        if(s[i]=='('){
            left++;}
           else if(s[i]==')'){
               if(left>0)left--;
               else right++;
               
           }
    }
    for(i=0;i<right;i++)printf("(");
    printf("%s",s);
    for(i=0;i<left;i++)printf(")");
    printf("\n");
    return 0;
           } ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %s",&n,s);
     ^