#include<stdio.h>
int main(){
    int m;
    scanf("%d",&m);
    int n=m/100;
    if (n<1){
        printf("00\n");
    }
    else if (n<=50){
        printf("%02d\n",n);
    }
    else if (n>=60&&n<=300){
        printf("%d\n",50+n/10);
    }
    else if (n>=350&&n<700){
        printf("%d\n",(n-300)/50+80);
    }
    else if (m==70000){
        printf("88\n");
    }
    else {
        printf("89\n");
    }
    return 0;
}