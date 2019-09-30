#include<stdio.h>

int main(){
    int a,b;

    scanf("%d %d",&a,&b);

    if(a==b){
        printf("Draw");
    }else if(a==1 || b==1){
        if(a<b){
            printf("Alice");
        }else{printf("Bob");}
    }else if(a<b){
        printf("Bob");
    }else if(a>b){
        printf("Alice");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^