#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char **a,**b;
    int n,m,i,j,k,l;
    scanf("%d%d",&n,&m);
    a=(char**) malloc(sizeof(char*)*n);
    for(i=0;i<n;i++){
        a[i]=(char*) malloc(sizeof(char)*n);
        scanf("%s",a[i]);
    }
    b=(char**) malloc(sizeof(char*)*m);
    for(i=0;i<m;i++){
        b[i]=(char*) malloc(sizeof(char)*m);
        scanf("%s",b[i]);
    }
    for(i=0;i<n-m+1;i++){
        for(j=0;j<n-m+1;j++){
            int match=1;
            for(k=0;k<m;k++){
                for(l=0;l<m;l++){
                    if(a[i+k][j+l]!=b[k][l]){
                        match=0;
                        break;
                    }
                }
            }
            if(match==1){
                printf("Yes\n");
                goto END;
            }
        }
    }
    printf("No\n");
    END:{
        for(i=0;i<n;i++) free(a[i]);
        free(a);
        for(i=0;i<m;i++) free(b[i]);
        free(b);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",a[i]);
         ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",b[i]);
         ^