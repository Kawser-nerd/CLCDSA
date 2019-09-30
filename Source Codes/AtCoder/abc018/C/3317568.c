#include <stdio.h>
#include <stdbool.h>
int min(int a, int b){return a<b?a:b;}
int main(void){
    int r,c,k,ans=0;
    scanf("%d%d%d",&r,&c,&k);
    char s[r][c+1];
    bool count[r][c];
    for (int i=0; i<r; i++){
        scanf("%s",s[i]);
        for (int j=0; j<c; j++){
            count[i][j]=true;
        }
    }
    for (int i=k-1; i<=r-k; i++){
        for (int j=k-1; j<=c-k; j++){
            count[i][j]=false;
        }
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (s[i][j]=='x'){
                for (int l=0; l<k; l++){
                    for (int m=0; m<k-l; m++){
                        count[i+l][j+m]=true;
                        count[i+l][j-m]=true;
                        count[i-l][j+m]=true;
                        count[i-l][j-m]=true;
                    }
                }
            }
        }
    }
    for (int i=k-1; i<=r-k; i++){
        for (int j=k-1; j<=c-k; j++){
            if (count[i][j]==false){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&r,&c,&k);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^