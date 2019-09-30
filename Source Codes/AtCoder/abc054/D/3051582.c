#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int min(int a,int b){
    if (a>b){
        return b;
    } else {
        return a;
    }
}

int main(void){
    int n,ma,mb,ans=1000000;
    scanf("%d%d%d",&n,&ma,&mb);
    int a[n],b[n],c[n];
    for (int i=0; i<n; i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    int d[n+1][420][420];
    for (int i=0; i<=n; i++){
        for (int j=0; j<=400; j++){
            for (int k=0; k<=400; k++){
                d[i][j][k]=1000000;
            }
        }
    }
    d[0][0][0]=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<=400; j++){
            for (int k=0; k<=400; k++){
                if(d[i][j][k]==1000000){
                    continue;
                }
                d[i+1][j][k]=min(d[i+1][j][k],d[i][j][k]);
                d[i+1][j+a[i]][k+b[i]]=min(d[i+1][j+a[i]][k+b[i]],d[i][j][k]+c[i]);
            }
        }
    }
    for (int j=1; j<=400; j++){
        for (int k=1; k<=400; k++){
            if (j*mb==k*ma){
                if(ans>d[n][j][k]){
                    ans=d[n][j][k];
                }
            }
        }
    }
    if (ans==1000000){
        printf("-1\n");
    } else {
        printf("%d\n",ans);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&ma,&mb);
     ^
./Main.c:21:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&a[i],&b[i],&c[i]);
         ^