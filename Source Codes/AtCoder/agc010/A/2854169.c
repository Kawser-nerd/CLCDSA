#include <stdio.h>

int main(void){
    int n,odd=0;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if (a[i]%2==1){
            odd++;
        }
    }
    if (odd%2==0){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^