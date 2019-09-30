#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<9; i++){
        if(111*i < n && n <= 111*(i+1)){
            printf("%d\n",(i+1)*111);
            break;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^