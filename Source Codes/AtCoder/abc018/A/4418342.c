#include <stdio.h>
int main(void){
    // Your code here!
    int n[4],cnt=3;
    for(int i=0;i<3;i++)
        scanf("%d",&n[i]);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(n[i]>n[j])
                cnt--;
        }
        printf("%d\n",cnt);
        cnt=3;
    }
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n[i]);
         ^