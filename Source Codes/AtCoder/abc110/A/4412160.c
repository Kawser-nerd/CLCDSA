#include <stdio.h>

int main()
{
    int a[3];
    scanf("%d%d%d",&a[0], &a[1], &a[2]);
    int ans;
    int temp;
    for(int i = 0; i < 3; i++){
        for(int j = i; j < 3; j++){
            if(a[i] < a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    ans = a[0]*10 + a[1] + a[2];
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a[0], &a[1], &a[2]);
     ^