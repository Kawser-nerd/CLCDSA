#include<stdio.h>
int main(void){
    int num;
    scanf("%d",&num);
    int x[num];int i,j;
  for(i=0;i<num;i++){
    scanf("%d",&x[i]);
  }
    int temp=0;

    int count;
    int sumA=0;
    int sumB=0;
    for(i=0;i<num;i++){
        for(j=i;j<num;j++){
            if(x[i]>x[j]){
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }

    for(i=num-1;i>=0;i-=2){
        sumA+=x[i];
    }
    for(i=num-2;i>=0;i-=2){
        sumB+=x[i];
    }
  
    printf("%d",sumA-sumB);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&num);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^