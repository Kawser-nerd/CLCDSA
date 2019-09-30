#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char s[3];
    int ans = 700;
    scanf("%s",s);
    for(int i=0; i<3; i++){
        if(s[i] == 'o'){
            ans += 100;
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^