#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    long long a[20],b[20];
    a[0]=1;b[0]=1;
    for(int i=1;i<20;i++){
        a[i]=a[i-1]*4;
    }
    for(int i=1;i<20;i++){
        b[i]=b[i-1]+a[i];
    }
    int x=0;
    for(int i=17;i>0;i--){
        if(n>b[i-1]&&b[i]>=n){
            printf("1");
            x=1;
            n-=a[i];
        }
        else if(x)printf("0");
        if(n>=0-(b[i]-1)/2&&0-(b[i-1]+1)/2>=n){
            printf("1");
            x=1;
            n+=a[i]/2;
        }
        else if(x)printf("0");
    }
    printf("%d\n",n);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^