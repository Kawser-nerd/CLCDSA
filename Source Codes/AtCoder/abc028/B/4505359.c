#include <stdio.h>
int main(void){
    // Your code here!
    char s[101],al[6]={'A','B','C','D','E','F'};
    int n[6]={0};
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        for(int j=0;j<6;j++){
            if(s[i]==al[j])
                n[j]++;
        }
    }
    for(int i=0;i<5;i++)
        printf("%d ",n[i]);
    printf("%d\n",n[5]);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^