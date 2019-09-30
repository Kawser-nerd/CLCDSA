#include<stdio.h>
#include<stdlib.h>
int main(){
    
    int a[51],b[51],c[51],d[51],n,m,i,j,p[51];
    
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d%d",&c[i],&d[i]);
    }
    for(i=0;i<n;i++){
        int min=500000000;
        for(j=0;j<m;j++){
            if(abs(a[i]-c[j])+abs(b[i]-d[j])<min){
                min=abs(a[i]-c[j])+abs(b[i]-d[j]);
                p[i]=j+1;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d\n",p[i]);
    }
    
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a[i],&b[i]);
         ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&c[i],&d[i]);
         ^