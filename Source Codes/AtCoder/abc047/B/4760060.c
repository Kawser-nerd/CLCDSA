#include <stdio.h>
int main(void){
    int w,h,n,x,y,a,xmax,xmin,ymax,ymin,i;
    scanf("%d%d%d",&w,&h,&n);
    xmax=0;
    xmin=w;
    ymax=0;
    ymin=h;
    for(i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&a);
        if(x>xmax && a==1) xmax=x;
        if(x<xmin && a==2) xmin=x;
        if(y>ymax && a==3) ymax=y;
        if(y<ymin && a==4) ymin=y;
    }
    if(xmax<xmin && ymax<ymin) printf("%d\n",(xmin-xmax)*(ymin-ymax));
    else printf("0\n");
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&w,&h,&n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&x,&y,&a);
         ^