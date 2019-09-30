#include<stdio.h>

 


int main(void){
    int n,max=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);   
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]<a[j+1]){
                int y;
                y=a[j+1];
                a[j+1]=a[j];
                a[j]=y;
            }
        }
    }

    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            max++;
        }
    }

    printf("%d",max+1);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);   
         ^