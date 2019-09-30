#include <stdio.h>

int main(){
    
    char a[4];
    int ans = 0;
    scanf("%s",a);
    for(int i=0; i<4; i++){
        if(a[i] == '+'){
            ans++;
        }else{
            ans--;
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a);
     ^