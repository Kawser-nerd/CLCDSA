#include <stdio.h>
int main(){
    int n;scanf("%d",&n);
    int l[n];
    int sum=0,max=0;
    for(int i=0;i<n;i++){
        scanf("%d",&l[i]);
        sum+=l[i];
        max=(max<l[i])?l[i]:max;
    }   
    if(sum-max>max)printf("Yes\n");
    else printf("No\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:3:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n;scanf("%d",&n);
           ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&l[i]);
         ^