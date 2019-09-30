#include <stdio.h>
int main()
{
    int n,a[101],i,grey=0,brown=0,green=0,aqours=0,blue=0,yellow=0,orange=0,
    red=0,colour=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<400){
            grey=1;
        }else if(a[i]<800){
            brown=1;
        }else if(a[i]<1200){
            green=1;
        }else if(a[i]<1600){
            aqours=1;
        }else if(a[i]<2000){
            blue=1;
        }else if(a[i]<2400){
            yellow=1;
        }else if(a[i]<2800){
            orange=1;
        }else if(a[i]<3200){
            red=1;
        }else{
            colour++;
        }
    }
    if(grey+brown+green+aqours+blue+yellow+orange+red==0){
        printf("1 %d",colour);
    }else{
    printf("%d %d",grey+brown+green+aqours+blue+yellow+orange+red,
    grey+brown+green+aqours+blue+yellow+orange+red+colour);}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^