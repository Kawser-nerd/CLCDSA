#include<stdio.h>
#include<math.h>

int wari(int j){
    int u;
    if(j/10==0){
        return j%10;
    }else{
        u=j%10;
        int h=wari(j/10);
        return u+h;

    }
    
}

int main(void){
    int a,b,n,sum=0;
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);
    for(int i=0;i<=n;i++){
        int h=wari(i);
        if(a<=h && h<=b){
            sum=sum+i;
        }
    }

    printf("%d\n",sum);


    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^