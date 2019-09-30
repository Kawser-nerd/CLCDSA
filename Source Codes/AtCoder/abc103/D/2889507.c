#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
    int n,m,near=0,ans=0;
    scanf("%d%d",&n,&m);
    int a[m],b[m],c[n];
    for (int i=0; i<n; i++){
        c[i]=1e9;
    }
    for (int i=0; i<m; i++){
        scanf("%d%d",&a[i],&b[i]);
        a[i]--;
        b[i]--;
        if(c[a[i]]>b[i]){
            c[a[i]]=b[i];
        }
    }
    for (int i=0; i<n; i++){
        if (c[i]!=1e9){
            if (i>=near){
                ans++;
                near=c[i];
            } else if (c[i]<near){
                near=c[i];
            }
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a[i],&b[i]);
         ^