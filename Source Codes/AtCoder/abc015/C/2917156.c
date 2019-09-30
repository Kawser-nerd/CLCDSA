#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int n,k,t[6][6];
bool found;

int dfs(int a, int b){
    if (b==n){
        if(a==0){
            found=true;
        }
        return 0;
    } else {
        for (int i=0; i<k; i++){
            dfs(a^t[b][i],b+1);
        }
    }
    return 0 ;
}

int main(void){
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            scanf("%d",&t[i][j]);
        }
    }
    for (int i=0; i<k; i++){
        dfs(t[0][i],1);
    }
    if (found==true){
        printf("Found\n");
    } else {
        printf("Nothing\n");
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:28:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&t[i][j]);
             ^