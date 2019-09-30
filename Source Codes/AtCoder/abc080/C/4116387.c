#include<stdio.h>
#include<string.h>
const int N = 1e5 + 10, INF = 0x3f3f3f3f ;
int main(){
    int a[N][15];
    int b[N][15];
    int temp[N];
    int n,i;
    scanf("%d",&n);
    for(i = 0;i < n;i++) {
        for(int j = 0;j < 10;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= 10;j++) {
            scanf("%d",&b[i][j]);
        }
    }
    long long int res = -INF;
    for(int i = 1;i < (1<<10);i++) {
        memset(temp,0,sizeof temp);
        for(int j = 0;j < n;j++) {
            for(int k = 0;k < 10;k++) {
                if(a[j][k] && ((1<<k)&i)) {
                    temp[j]++;
                }
            }
        }
        long long int t = 0;
        for(int j = 0;j < n;j++) {
            t += b[j][temp[j]];
        }
        if(res<t)
            res=t;
    }
    printf("%lld",res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&a[i][j]);
             ^
./Main.c:17:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&b[i][j]);
             ^