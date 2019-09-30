#include <stdio.h>

int main() {
    int n;
    long int keep = 0;
    int a[100000]; // less than O(n)
    int b[100000];
    
    //input
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    
    //calculation
    for(int i = n-1; i >= 0; i--){
        keep += (b[i]-(a[i]+keep)%b[i])%b[i];
    }
    
    //Output
    printf("\n%ld\n",keep);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a[i],&b[i]);
         ^