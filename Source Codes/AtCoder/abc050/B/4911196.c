#include <stdio.h>
int main(void)
{
    int n;
    int ans;
    scanf("%d", &n);
    int t[n];
    for(int i=0; i<n; i++) scanf("%d", &t[i]);
    int m;
    scanf("%d", &m);
    int p[m], x[m];
    for(int i=0; i<m; i++) scanf("%d%d", &p[i], &x[i]);
    
    int pre=0;
    for(int i=0; i<n; i++) pre+=t[i];
    for(int i=0; i<m; i++)
    {
        ans=ans-t[p[i]]+x[i];
        printf("%d\n", pre-t[p[i]-1]+x[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:8:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0; i<n; i++) scanf("%d", &t[i]);
                            ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &m);
     ^
./Main.c:12:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0; i<m; i++) scanf("%d%d", &p[i], &x[i]);
                            ^