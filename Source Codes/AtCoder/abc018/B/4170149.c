#include<stdio.h>

int main(){
    int n, i, j, k;
    char str[101],work;
    int l[100],r[100];

    scanf("%s",str);
    scanf("%d",&n);

    for(k=0;k<n;k++){
        scanf("%d %d",&l[k],&r[k]);
    }

    for(i=0;i<n;i++){
        for(j=l[i]-1;;){
            for(k=r[i]-1;k>j;k--){
                work = str[j];
                str[j] = str[k];
                str[k] = work;
                j++;
            }
            break;
        }
    }
    printf("%s\n",str);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",str);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&l[k],&r[k]);
         ^