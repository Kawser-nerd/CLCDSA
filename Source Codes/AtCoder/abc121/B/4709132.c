#include <stdio.h>
int b[30];
int main(void){
    int n,m,c,res=0;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=0;i<m;i++) scanf("%d",b+i);
    for(int i=0;i<n;i++){
        int a,sum=c;
        for(int j=0;j<m;j++){
            scanf("%d",&a);
            sum+=a*b[j];
        }
        if(sum>0) res++;
    }
    printf("%d\n",res);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&m,&c);
     ^
./Main.c:6:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<m;i++) scanf("%d",b+i);
                          ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&a);
             ^