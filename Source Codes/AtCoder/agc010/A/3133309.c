#include <stdio.h>
int main(void){
    // Your code here!
    int i, N, cnt = 0;
    long int a[100001];
    
    scanf("%d", &N);
    
    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
        if(a[i] % 2 != 0) cnt++;
    }
    
    if(cnt % 2 == 0) printf("YES");
    else printf("NO");
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:15: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
         scanf("%d", &a[i]);
               ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^