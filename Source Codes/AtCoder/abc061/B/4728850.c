#include<stdio.h>
#include<math.h>

int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[m],b[m];
    int c[n+1];
    int d[n+1];
    for(int i=0;i<m;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i=0;i<=n;i++){
        c[i]=0;
        d[i]=0;
    }
    for(int i=0;i<m;i++){
        c[a[i]]++;
        d[b[i]]++;

    }
    
    for(int i=1;i<=n;i++){
        printf("%d\n",c[i]+d[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a[i],&b[i]);
         ^