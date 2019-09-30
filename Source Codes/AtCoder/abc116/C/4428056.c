#include <stdio.h>
int main(void)
{
    int n, h[100], i, ans=0, p, cnt=0;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &h[i]);
    }

    while(1){
        p=0;cnt=0;
        for(i=0;i<n;i++){
            if(h[i] != 0){
                p=1;
                h[i]=h[i]-1;
            }
            else if(h[i]==0 && p==1){
                break;
            }
        }
        if(p==1) ans++;
        for(i=0;i<n;i++){
            if(h[i]==0) cnt++;
        }
        if(cnt==n) break;
    }
            
                
    printf("%d\n", ans);          

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &h[i]);
         ^