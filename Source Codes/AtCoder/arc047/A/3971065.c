#include <string.h>
#include <stdio.h>

int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    char s[n+1];
    scanf("%s",s);
    int tab=1,crash=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+'){
            tab++;
            if(tab==l+1){tab=1;
            crash++;}
        }else{
            tab--;
        }
    }
    printf("%d\n",crash);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&l);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^