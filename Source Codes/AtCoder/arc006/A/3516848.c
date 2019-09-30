#include <stdio.h>
int main(void){
    int e[6],b,l,ans=0,bonus=0;
    scanf("%d%d%d%d%d%d%d",&e[0],&e[1],&e[2],&e[3],&e[4],&e[5],&b);
    for (int i=0; i<6; i++){
        scanf("%d",&l);
        for (int j=0; j<6; j++){
            if (l==e[j]){
                ans++;
            }
        }
        if (l==b){
            bonus=1;
        }
    }
    if (ans==6){
        printf("1\n");
    } else if (ans==5 && bonus==1){
        printf("2\n");
    } else if (ans==5){
        printf("3\n");
    } else if (ans==4){
        printf("4\n");
    } else if (ans==3){
        printf("5\n");
    } else {
        printf("0\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d%d",&e[0],&e[1],&e[2],&e[3],&e[4],&e[5],&b);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&l);
         ^