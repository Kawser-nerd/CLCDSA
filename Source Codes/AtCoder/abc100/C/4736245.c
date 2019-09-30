#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MIN 1E9
#define MAX -10000000

int main(void){
    int n,a[10100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int ans=0;
    for(int i=0;i<n;i++){
        int sum=0;
        while(a[i]%2==0){
            a[i]/=2;
            sum++;
        }
        ans+=sum;
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<n;i++)scanf("%d",&a[i]);
                         ^