#include<stdio.h>

void input(int*,int*,int*);
int ans(int,int,int);
int main(void){
    int a,b,k;
    int anse;
    input(&a,&b,&k);
    anse=ans(a,b,k);
    printf("%d\n",anse);
    return 0;
}
void input(int* a,int* b,int* k){
    scanf("%d %d %d",a,b,k);
}
int ans(int p,int q,int r){
    int a=0;
    int i=p;
    int counter=0;
    while(counter<r){
        if(p%i==0 && q%i==0){
            a=i;
            counter++;
        }
        i--;
    }

    return a;
} ./Main.c: In function ‘input’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",a,b,k);
     ^