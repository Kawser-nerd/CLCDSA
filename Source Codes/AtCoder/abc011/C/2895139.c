#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    int n,ng[3];
    scanf("%d%d%d%d",&n,&ng[0],&ng[1],&ng[2]);
    if (n==ng[0] || n==ng[1] || n==ng[2]){
        printf("NO\n");
        return 0 ;
    }
    for (int i=0; i<100; i++){
        if (n-3!=ng[0] && n-3!=ng[1] && n-3!=ng[2]){
            n=n-3;
        } else if (n-2!=ng[0] && n-2!=ng[1] && n-2!=ng[2]){
            n=n-2;
        } else if (n-1!=ng[0] && n-1!=ng[1] && n-1!=ng[2]){
            n=n-1;
        }
    }
    if (n<=0){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&n,&ng[0],&ng[1],&ng[2]);
     ^