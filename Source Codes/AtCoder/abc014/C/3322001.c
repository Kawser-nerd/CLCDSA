#include <stdio.h>

int main(void){
    int n,a,b;
    scanf("%d",&n);
    int count[1000001];
    for (int i=0; i<1000001; i++){
        count[i]=0;
    }
    for (int i=0; i<n; i++){
        scanf("%d%d",&a,&b);
        count[a]++;
        count[b+1]--;
    }
    for (int i=1; i<1000001; i++){
        count[i]+=count[i-1];
        if (count[0]<count[i]){
            count[0]=count[i];
        }
    }
    printf("%d\n",count[0]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a,&b);
         ^