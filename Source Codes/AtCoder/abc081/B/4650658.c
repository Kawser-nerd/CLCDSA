#include<stdio.h>
#include<math.h>

int wari(int j){
    int a=0;
    if(j%2==0){
        int b=wari(j/2);
        return 1+b;
    }else{
        return 0;
    }
}

int main(void){
    int u,n,t=pow(10,9);
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]%2==1){
            printf("0\n");
            return 0;
        }
        if(a[i]%u!=0){
            t=wari(a[i]);
            u=pow(2,t);
        }
    }
    printf("%d",t);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^