#include <stdio.h>
int main(void){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    int count[n];
    for (int i=0; i<n; i++){
        count[i]=0;
    }
    for (int i=0; i<m; i++){
        scanf("%d%d",&a,&b);
        count[a-1]++;
        count[b-1]++;
    }
    for (int i=0; i<n; i++){
        if (count[i]%2!=0){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a,&b);
         ^