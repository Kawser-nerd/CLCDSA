#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int main(void){
    int n,m,ans=1;
    scanf("%d%d",&n,&m);
    int x,y,q[n];
    bool p[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            p[i][j]=false;
        }
    }
    for (int i=0; i<m; i++){
        scanf("%d%d",&x,&y);
        p[x-1][y-1]=true;
        p[y-1][x-1]=true;
    }
    for (int i=0; i<n; i++){
        p[i][i]=true;
    }
    
    for (int i=0; i<(1<<n); i++){
        int tmp=0,count=0;
        bool kl=false;
        for (int j=0; j<n; j++){
           if ((1&i>>j)==1){
               q[count]=j;
               count++;
           }
        }
        for (int j=0; j<count; j++){
            for (int k=0; k<count; k++){
                if(p[q[j]][q[k]]==false){
                    kl=true;
                }
            }
        }
        if (kl==false){
            tmp=count;
        } else {
            tmp=-1;
        }
        if (ans<tmp){
            ans=tmp;
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&x,&y);
         ^